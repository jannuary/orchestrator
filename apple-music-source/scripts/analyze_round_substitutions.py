"""Check whether one shared byte encoding explains mixing and substitutions.

All inferred encodings, scalars and translations stay in RAM. This is bounded
developer analysis, not a shipped cipher/key provider or complete AES proof.
"""
from collections import Counter
from itertools import permutations

from analyze_table_algebra import Basis,apply,independent,_field_models,FORWARD,INVERSE

_NORMALIZATIONS=None


def normalizations():
    global _NORMALIZATIONS
    if _NORMALIZATIONS is not None:return _NORMALIZATIONS
    from apple_music_source.crypto.aes import _gmul,_gpow
    result={};inverse={x:_gpow(x,254) for x in range(1,256)}
    for name,matrix in (('AES-forward-MixColumns',FORWARD),('AES-inverse-MixColumns',INVERSE)):
        for rows in permutations(range(4)):
            for columns in permutations(range(4)):
                labels=tuple(_gmul(_gmul(matrix[rows[0]][columns[0]],matrix[rows[j]][columns[i]]),
                                   inverse[_gmul(matrix[rows[j]][columns[0]],matrix[rows[0]][columns[i]])])
                             for i in range(4) for j in range(4))
                result.setdefault(labels,[]).append((name,matrix,rows,columns))
    _NORMALIZATIONS=result;return result


def derivative(values):
    result=[0]
    for delta in range(1,256):
        counts=Counter(values[x]^values[x^delta] for x in range(256))
        if Counter(counts.values())!=Counter({2:126,4:1}):return None
        result.append(next(word for word,count in counts.items() if count==4))
    return result


def analyze(arrays,regular,model_callback=None):
    from apple_music_source.crypto.aes import _SBOX,_INV_SBOX,_gmul,_gpow
    words=[[int.from_bytes(arrays[ordinal][i:i+4],'little') for i in range(0,1024,4)] for ordinal in regular]
    spaces=[independent([word^table[0] for word in table]) for table in words]
    result=dict(regular_table_ordinals=list(regular),parameters_emitted=False)
    if any(len(space)!=8 for space in spaces):return dict(result,status='unsupported word rank')
    projected=[[tuple((word>>(8*j))&255 for word in space) for j in range(4)] for space in spaces]
    if any(len(independent(columns))!=8 for row in projected for columns in row):
        return dict(result,status='unsupported byte projection rank')
    maps=[]
    for row in projected:
        source=Basis(row[0]);maps.append([tuple(apply(matrix,source.coordinates(1<<k)) for k in range(8)) for matrix in row])
    cross_ratios=[]
    for row in maps:
        for j,matrix in enumerate(row):
            inverse=Basis(maps[0][j]);cross_ratios.append(tuple(inverse.coordinates(column) for column in matrix))
    models=_field_models(cross_ratios)
    if models is None:return dict(result,status='no common byte field')
    source_derivatives=[derivative(table) for table in words]
    result['all_regular_tables_have_inversion_derivatives']=all(table is not None for table in source_derivatives)
    if not result['all_regular_tables_have_inversion_derivatives']:return dict(result,status='unsupported substitution derivative')
    spec=(('AES-S-box',_SBOX,derivative(list(_SBOX))),('AES-inverse-S-box',_INV_SBOX,derivative(list(_INV_SBOX))))
    inverse={x:_gpow(x,254) for x in range(1,256)};normal=normalizations()
    expected_count=scale_trials=derivative_candidates=full_candidates=0;families=set();positions=set()
    for labels,decoder0 in models:
        for mix_name,matrix,rows,columns in normal.get(labels,()):
            expected_count+=1
            coefficients=[[matrix[rows[j]][columns[i]] for j in range(4)] for i in range(4)]
            decoders=[]
            for j in range(4):
                back=Basis(maps[0][j]);ratio=_gmul(coefficients[0][j],inverse[coefficients[0][0]])
                decoders.append(tuple(_gmul(ratio,apply(decoder0,back.coordinates(1<<k))) for k in range(8)))
            input_positions=tuple(rows.index(columns[i]) for i in range(4))
            logical_derivatives=[];logical_values=[]
            for i,position in enumerate(input_positions):
                back=Basis(decoders[position]);factor=inverse[coefficients[i][0]]
                logical_derivatives.append([_gmul(factor,apply(decoder0,source_derivatives[i][back.coordinates(x)]&255)) for x in range(256)])
                logical_values.append([_gmul(factor,apply(decoder0,(words[i][back.coordinates(x)]^words[i][0])&255)) for x in range(256)])
            for spec_name,box,spec_derivative in spec:
                for scale in range(1,256):
                    scale_trials+=1;back_scale=inverse[scale]
                    if not all(_gmul(scale,table[_gmul(back_scale,x)])==spec_derivative[x]
                               for table in logical_derivatives for x in range(1,256)):continue
                    derivative_candidates+=1;translations=[]
                    for table in logical_values:
                        value=[_gmul(scale,table[_gmul(back_scale,x)]) for x in range(256)]
                        translated=next((shift for shift in range(256)
                                         if all(value[x]==(box[x^shift]^box[shift]) for x in range(256))),None)
                        if translated is None:break
                        translations.append(translated)
                    if len(translations)!=4:continue
                    full_candidates+=1;families.add((mix_name,spec_name));positions.add(input_positions)
                    if model_callback is not None:
                        model_callback(dict(decoders=[tuple(_gmul(scale,column) for column in decoder) for decoder in decoders],
                                            input_positions=input_positions,translations=translations,
                                            input_rows=columns,output_rows=rows,
                                            mixing_coefficients=coefficients,mix_name=mix_name,spec_name=spec_name))
    result.update(status='complete bounded shared-encoding search',field_normalizations_checked=expected_count,
                  common_scale_hypotheses_checked=scale_trials,derivative_candidates=derivative_candidates,
                  full_substitution_candidates=full_candidates,
                  coherent_families=[dict(mixing=mix_name,substitution=spec_name) for mix_name,spec_name in sorted(families)],
                  coherent_input_byte_position_permutations=[list(position) for position in sorted(positions)],
                  scope='one common linear byte encoding, coherent row/column assignment and input/output XOR translations; no round-key, ShiftRows, full cipher or auth proof')
    return result
