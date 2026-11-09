"""Identify encoded word-mixing spaces; all inferred bases stay in RAM.

This is developer analysis, not a table initializer or runtime provider. Matching
MixColumns up to linear coordinate changes does not identify a whole cipher,
round keys, external encodings, or a standalone implementation.
"""
from itertools import permutations
from collections import Counter


def independent(columns):
    rows={};result=[]
    for column in columns:
        x=column
        while x:
            bit=x.bit_length()-1
            if bit in rows:x^=rows[bit]
            else:rows[bit]=x;result.append(column);break
    return result


class Basis:
    def __init__(self,columns):
        self.rows={}
        for index,column in enumerate(columns):
            x=column;label=1<<index
            while x:
                bit=x.bit_length()-1
                if bit in self.rows:
                    old,old_label=self.rows[bit];x^=old;label^=old_label
                else:self.rows[bit]=(x,label);break

    def coordinates(self,value):
        result=0
        while value:
            bit=value.bit_length()-1
            if bit not in self.rows:raise ValueError('outside source span')
            column,label=self.rows[bit];value^=column;result^=label
        return result


def apply(columns,value):
    result=0
    for i,column in enumerate(columns):
        if value&(1<<i):result^=column
    return result


IDENTITY=tuple(1<<i for i in range(8))


def compose(left,right):return tuple(apply(left,column) for column in right)
def packed(matrix):return sum(column<<(8*i) for i,column in enumerate(matrix))
def unpacked(value):return tuple((value>>(8*i))&255 for i in range(8))


def power(matrix,exponent):
    result=IDENTITY
    while exponent:
        if exponent&1:result=compose(result,matrix)
        matrix=compose(matrix,matrix);exponent>>=1
    return result


def _field_models(matrices):
    """Recover every GF(256) isomorphism of a verified matrix field, RAM-only."""
    from apple_music_source.crypto.aes import _gmul
    if any(compose(a,b)!=compose(b,a) for a in matrices for b in matrices):return None
    generators=independent([packed(IDENTITY)]+[packed(matrix) for matrix in matrices])
    while True:
        if len(generators)>8:return None
        products=[packed(compose(unpacked(a),unpacked(b))) for a in generators for b in generators]
        expanded=independent(generators+products)
        if len(expanded)==len(generators):break
        generators=expanded
    if len(generators)!=8:return None
    elements=[unpacked(apply(generators,value)) for value in range(1,256)]
    if any(len(independent(matrix))!=8 for matrix in elements):return None
    generator=next(matrix for matrix in elements if all(power(matrix,255//p)!=IDENTITY for p in (3,5,17)))
    assert power(generator,255)==IDENTITY
    powers=[power(generator,i) for i in range(8)];basis=Basis([packed(m) for m in powers])
    assert len(basis.rows)==8
    polynomial=basis.coordinates(packed(power(generator,8)))
    def evaluate(coefficients,root):
        result=0;term=1
        for bit in range(9):
            if coefficients&(1<<bit):result^=term
            term=_gmul(term,root)
        return result
    roots=[root for root in range(1,256) if evaluate(polynomial|256,root)==0]
    assert len(roots)==8
    labels=[basis.coordinates(packed(matrix)) for matrix in matrices]
    vector_basis=Basis([apply(matrix,1) for matrix in powers]);assert len(vector_basis.rows)==8
    return [(tuple(evaluate(label,root) for label in labels),
             tuple(evaluate(vector_basis.coordinates(1<<bit),root) for bit in range(8))) for root in roots]


def field_labels(matrices):
    models=_field_models(matrices)
    return None if models is None else [labels for labels,decoder in models]


FORWARD=((2,3,1,1),(1,2,3,1),(1,1,2,3),(3,1,1,2))
INVERSE=((14,11,13,9),(9,14,11,13),(13,9,14,11),(11,13,9,14))
_EXPECTED=None


def expected_cross_ratios():
    global _EXPECTED
    if _EXPECTED is not None:return _EXPECTED
    from apple_music_source.crypto.aes import _gmul,_gpow
    expected={}
    inverse={x:_gpow(x,254) for x in range(1,256)}
    for name,matrix in (('AES-forward-MixColumns',FORWARD),('AES-inverse-MixColumns',INVERSE)):
        for rows in permutations(range(4)):
            for columns in permutations(range(4)):
                coefficients=[]
                for i in range(4):
                    for j in range(4):
                        numerator=_gmul(matrix[rows[0]][columns[0]],matrix[rows[j]][columns[i]])
                        denominator=_gmul(matrix[rows[j]][columns[0]],matrix[rows[0]][columns[i]])
                        coefficients.append(_gmul(numerator,inverse[denominator]))
                expected.setdefault(tuple(coefficients),set()).add(name)
    _EXPECTED=expected;return expected


def analyze(arrays,regular,final):
    assert len(arrays)==8 and len(regular)==len(final)==4
    assert set(regular).isdisjoint(final) and set(regular)|set(final)==set(range(8))
    spaces=[];byte_ranks=[];affine_maps=[];inversion_structure=[]
    for data in arrays:
        assert len(data)==1024
        words=[int.from_bytes(data[i:i+4],'little') for i in range(0,1024,4)]
        differences=[word^words[0] for word in words]
        columns=[differences[1<<j] for j in range(8)]
        affine=all(apply(columns,x)==differences[x] for x in range(256));affine_maps.append(affine)
        inversion=True
        if affine:inversion=False
        else:
            for delta in range(1,256):
                counts=Counter(words[x]^words[x^delta] for x in range(256))
                if Counter(counts.values())!=Counter({2:126,4:1}):inversion=False;break
        inversion_structure.append(inversion)
        spaces.append(independent(differences))
        byte_ranks.append([len(independent([(word>>(8*j))&255 for word in differences])) for j in range(4)])
    result=dict(word_space_ranks=[len(space) for space in spaces],byte_projection_ranks=byte_ranks,
                input_maps_affine=affine_maps,inversion_differential_structure=inversion_structure,
                regular_table_ordinals=list(regular),final_table_ordinals=list(final),parameters_emitted=False)
    if any(len(space)!=8 for space in spaces):return result
    final_basis=Basis([column for ordinal in final for column in spaces[ordinal]])
    result['combined_final_space_rank']=len(final_basis.rows)
    if len(final_basis.rows)!=32:return result
    projected=[]
    for ordinal in regular:
        coordinates=[final_basis.coordinates(column) for column in spaces[ordinal]]
        projected.append([tuple((word>>(8*j))&255 for word in coordinates) for j in range(4)])
    ranks=[[len(independent(matrix)) for matrix in row] for row in projected]
    result['regular_to_final_projection_ranks']=ranks
    if any(rank!=8 for row in ranks for rank in row):return result
    maps=[]
    for row in projected:
        source=Basis(row[0]);maps.append([tuple(apply(matrix,source.coordinates(1<<k)) for k in range(8)) for matrix in row])
    cross_ratios=[]
    for row in maps:
        for j,matrix in enumerate(row):
            inverse=Basis(maps[0][j]);cross_ratios.append(tuple(inverse.coordinates(column) for column in matrix))
    labels=field_labels(cross_ratios)
    result['common_GF256_matrix_field']=labels is not None
    if labels is not None:
        expected=expected_cross_ratios();families=set()
        for label in labels:families.update(expected.get(label,()))
        result['field_isomorphisms_checked']=len(labels)
        result['MixColumns_equivalence_families']=sorted(families)
    result['scope']='word-space linear equivalence and GF(256) mixing only; no recovered encodings emitted and no full cipher/key/auth identity'
    return result
