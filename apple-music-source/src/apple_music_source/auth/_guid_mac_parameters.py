"""Named static parameter for the native Android MAC-derived GUID field.

SHA1_SUFFIX is the 32-byte suffix in SHA1(raw_MAC || suffix)[:7].
Provenance: pinned CoreFP SHA-256
cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175,
read-only virtual/file interval 0x23954c..0x23956c. Native storage uses the
byte codec (23*x+98) mod 256; its inverse is (167*x+18) mod 256.
Complete native SHA-1 schedule, padding and final-field comparisons establish
this parameter's message-suffix role; no cipher/integrity lookup bank is used.
This is a static protocol parameter, never an account or device secret.
"""

SHA1_SUFFIX = bytes.fromhex(
    '6536613735356138393635373633613839386639333236656261303436363435'
)
