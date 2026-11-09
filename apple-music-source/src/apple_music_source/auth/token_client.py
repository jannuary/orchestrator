"""Source-only native developer/Music user token exchange.

Uses caller-owned native session state, source CoreADI machine data and source
Mescal signatures. SDK calls in lite/tokens.cpp are replaced by HTTPS requests;
neither an original library nor a cached token from another account is loaded.
"""
import base64
from dataclasses import dataclass, field
import json
import os
from pathlib import Path
import tempfile
import time
from urllib.parse import urlencode, urlsplit, urlunsplit

from .http_transport import apple_https_url
from .login_client import resolve_bag_url

USER_AGENT = 'Music/5.0.2 Android/10 model/Pixel 8 build/7663314 (dt:66)'


def _safe(value):
    if not isinstance(value, str) or any(char in value for char in '\r\n\0'):
        raise ValueError('invalid token request value')
    return value


def api_token_signing_bytes(url, headers, parameters, bag):
    """Concatenate selected header/parameter values in URL-bag array order.

    URLBag::stringToSignWithApiTokenURLRequest (ELF 0x119380) appends trimmed
    present header values, then raw present parameter values, without separators.
    Missing values contribute nothing. Header lookup is case insensitive;
    request-parameter lookup is case sensitive. No timestamp is fabricated.
    """
    component = urlsplit(url).path.rsplit('/', 1)[-1]
    group = bag.get('signed-actions')
    group = group.get('apiToken') if isinstance(group, dict) else None
    policy = group.get(component) if isinstance(group, dict) else None
    if not isinstance(policy, dict):
        raise ValueError('URL bag has no API-token signing policy')
    if not all(isinstance(policy.get(key, []), list) for key in ('headers', 'fields')):
        raise ValueError('invalid API-token signing arrays')
    normalized = {key.lower(): _safe(value) for key, value in headers.items()}
    values = []
    for key in policy.get('headers', []):
        if not isinstance(key, str):
            raise ValueError('invalid API-token header policy')
        if key.lower() in normalized:
            values.append(normalized[key.lower()].strip(' \t\r\n\v\f'))
    for key in policy.get('fields', []):
        if not isinstance(key, str):
            raise ValueError('invalid API-token field policy')
        if key in parameters:
            values.append(_safe(parameters[key]))
    data = ''.join(values).encode('utf-8')
    if not data:
        raise ValueError('API-token signing string is empty')
    return data


class TokenServiceError(RuntimeError):
    def __init__(self, stage, status, fields=()):
        self.stage, self.http_status, self.response_fields = stage, status, tuple(fields)
        super().__init__('%s failed (HTTP %d)' % (stage, status))


def _response_token(response, field, stage):
    try:
        data = json.loads(response.body)
    except (ValueError, UnicodeError):
        raise TokenServiceError(stage, response.status) from None
    fields = tuple(data) if isinstance(data, dict) else ()
    token = data.get(field) if isinstance(data, dict) else None
    if not 200 <= response.status < 300 or not isinstance(token, str) or not 0 < len(token) <= 1048576:
        raise TokenServiceError(stage, response.status, fields)
    return _safe(token)


@dataclass(frozen=True)
class WebTokens:
    dev_token: str = field(repr=False)
    music_token: str = field(repr=False)
    storefront_id: str = ''

    def __post_init__(self):
        if not _safe(self.dev_token) or not _safe(self.music_token):
            raise ValueError('both server-issued tokens are required')
        _safe(self.storefront_id)

    def save(self, directory):
        """Publish a private token pair in the native client cache format."""
        directory = Path(directory)
        data = dict(dev_token=self.dev_token, music_token=self.music_token,
                    storefront_id=self.storefront_id)
        outputs = {'DEV_TOKEN': self.dev_token, 'MUSIC_TOKEN': self.music_token,
                   'STOREFRONT_ID': self.storefront_id,
                   'token_cache.json': json.dumps(data)}
        # Legacy token files are compatibility copies; token_cache.json is the
        # atomic canonical pair and is published after those copies are ready.
        for name, value in outputs.items():
            fd, temporary = tempfile.mkstemp(prefix='.' + name + '-', dir=directory)
            try:
                with os.fdopen(fd, 'w') as stream:
                    stream.write(value)
                    stream.flush()
                    os.fsync(stream.fileno())
                os.replace(temporary, directory / name)
            finally:
                if os.path.exists(temporary):
                    os.unlink(temporary)


def verify_amp_tokens(transport, tokens, *, user_agent=USER_AGENT):
    """Read the authenticated storefront and return a region-ready token pair."""
    response = transport.get('https://amp-api.music.apple.com/v1/me/storefront', {
        'Authorization': 'Bearer ' + tokens.dev_token,
        'media-user-token': tokens.music_token, 'Origin': 'https://music.apple.com',
        'Accept': 'application/json', 'User-Agent': user_agent}, timeout=45)
    if response.status != 200:
        raise TokenServiceError('amp-verification', response.status)
    try:
        data = json.loads(response.body)
    except (ValueError, UnicodeError):
        raise TokenServiceError('amp-verification', response.status) from None
    rows = data.get('data') if isinstance(data, dict) else None
    if (not isinstance(rows, list) or not rows or not isinstance(rows[0], dict)
            or not isinstance(rows[0].get('id'), str) or not rows[0]['id']):
        raise ValueError('AMP did not return an account storefront')
    return (WebTokens(tokens.dev_token, tokens.music_token, rows[0]['id']),
            {'amp_http_status': response.status, 'amp_response_bytes': len(response.body),
             'storefront': rows[0]['id']})


class TokenClient:
    def __init__(self, *, session, guid, bag, transport, machine_data, signer,
                 storefront='', user_agent=USER_AGENT, clock=time.time):
        self.session, self.guid, self.bag = session, _safe(guid), bag
        if not self.guid:
            raise ValueError('matching saved device GUID is required')
        self.transport, self.machine_data, self.signer = transport, machine_data, signer
        self.storefront = _safe(storefront or session.storefront)
        self.user_agent, self.clock = _safe(user_agent), clock

    def _headers(self):
        proof = self.machine_data.otp(-1)
        if not proof.mid or not proof.otp:
            raise ValueError('source machine data is unavailable')
        headers = {'User-Agent': self.user_agent, 'Accept': 'application/json',
                   'Accept-Language': 'en-US', 'X-Dsid': str(self.session.dsid),
                   'X-Token': _safe(self.session.token),
                   'X-Apple-AMD-M': base64.b64encode(proof.mid).decode('ascii'),
                   'X-Apple-AMD': base64.b64encode(proof.otp).decode('ascii')}
        if self.storefront:
            headers['X-Apple-Store-Front'] = self.storefront
        return headers

    def developer_token(self):
        url = resolve_bag_url(self.bag, 'sf-api-token-service-url')
        parsed = apple_https_url(url)
        parameters = {'clientId': 'musicAndroid', 'version': '1'}
        if parsed.query:
            raise ValueError('unexpected API-token base query')
        headers = self._headers()
        signature = self.signer.sign(api_token_signing_bytes(url, headers, parameters, self.bag))
        if not signature:
            raise ValueError('source API-token signature is unavailable')
        headers['X-Apple-ActionSignature'] = base64.b64encode(signature).decode('ascii')
        url = urlunsplit((parsed.scheme, parsed.netloc, parsed.path, urlencode(parameters), ''))
        response = self.transport.get(url, headers, timeout=45)
        return _response_token(response, 'token', 'developer-token')

    def music_user_token(self, developer_token):
        url = resolve_bag_url(self.bag, 'createMusicToken')
        apple_https_url(url)
        body = json.dumps({'guid': self.guid, 'assertion': _safe(developer_token),
                           'tcc-acceptance-date': str(int(self.clock() * 1000))},
                          separators=(',', ':')).encode('utf-8')
        headers = self._headers()
        headers.update({'Content-Type': 'application/json; charset=UTF-8',
                        'X-Apple-Requesting-Bundle-Id': 'com.apple.android.music',
                        'X-Apple-Requesting-Bundle-Version': self.user_agent})
        # The pinned bag selects anonymous AMD but no Mescal/priming for this
        # URL. Do not copy the developer-token request's signature to this body.
        response = self.transport.post(url, body, headers, timeout=45)
        return _response_token(response, 'music_token', 'music-user-token')

    def acquire(self):
        developer = self.developer_token()
        return WebTokens(developer, self.music_user_token(developer), self.storefront)
