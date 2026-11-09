"""Classify synthetic runtime lookup arrays without recording their contents.

Developer-only helper. All candidate values, translations and comparison
parameters remain in RAM. A match establishes the tested array relation, not
the complete cipher or key independence.
"""
from collections import Counter


def rank(values):
    basis={}
    for value in values:
        for bit in sorted(basis,reverse=True):
            if value&(1<<bit):value^=basis[bit]
        if value:basis[value.bit_length()-1]=value
    return len(basis)


def xor_relation(base,current,expected_output_delta=None,expected_input_shift=None):
    """Count exact input/output XOR translations; parameters stay local."""
    assert len(base)==len(current)==1024
    a=[int.from_bytes(base[j:j+4],'little') for j in range(0,1024,4)]
    b=[int.from_bytes(current[j:j+4],'little') for j in range(0,1024,4)]
    matches=0
    for shift in range(256):
        if expected_input_shift is not None and shift!=expected_input_shift:continue
        delta=a[shift]^b[0]
        if expected_output_delta is not None and delta!=expected_output_delta:continue
        if all((a[x^shift]^delta)==value for x,value in enumerate(b)):
            matches+=1
    return matches


def classify(data):
    from apple_music_source.crypto.aes import _SBOX,_INV_SBOX,_gmul
    width=len(data)//256
    assert width in (1,4) and len(data)==256*width
    values=[int.from_bytes(data[width*i:width*(i+1)],'little') for i in range(256)]
    result=dict(entry_bytes=width,distinct_values=len(set(values)),
                affine_rank=rank([value^values[0] for value in values]))
    if result['distinct_values']!=256 or result['affine_rank']!=8:return result
    patterns=[]
    if width==1:patterns=[('AES-S-box',list(_SBOX)),('AES-inverse-S-box',list(_INV_SBOX))]
    else:
        for name,box,coefficients in (('AES-forward-T',_SBOX,(2,1,1,3)),
                                      ('AES-inverse-T',_INV_SBOX,(14,9,13,11))):
            for rotation in range(4):
                coeff=coefficients[rotation:]+coefficients[:rotation]
                for reverse in (False,True):
                    lanes=coeff[::-1] if reverse else coeff
                    patterns.append((name,[sum(_gmul(x,c)<<(8*i) for i,c in enumerate(lanes)) for x in box]))
    exact=set();translated=set()
    for name,pattern in patterns:
        if values==pattern:exact.add(name)
        # Only bounded XOR input/output translations; never emit parameters.
        for shift in range(256):
            delta=values[0]^pattern[shift]
            if all(value==(pattern[x^shift]^delta) for x,value in enumerate(values)):
                translated.add(name)
    result.update(exact_standard_families=sorted(exact),xor_translated_standard_families=sorted(translated))
    return result


def allocations(mu,allocated):
    rows=[]
    for ordinal,(address,size) in enumerate(allocated):
        for width in (1,4):
            length=256*width
            if size not in (256,260,264,1024,1028,1032) or size<length:continue
            # Packet helpers over-allocate both byte and word arrays. Preserve
            # all three bounded prefix hypotheses rather than assuming that
            # requested allocation length is the lookup's element width.
            for offset in range(0,min(size-length,8)+1,4):
                rows.append(dict(allocation_ordinal=ordinal,allocation_size=size,offset=offset,
                                 **classify(bytes(mu.mem_read(address+offset,length)))))
    return dict(allocation_sizes=dict(Counter(size for _,size in allocated)),arrays=rows)
