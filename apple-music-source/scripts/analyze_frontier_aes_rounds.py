"""Test a nearest-round dependency-frontier hypothesis against AES keys.

Older edges are projected away and ambiguous unions are resolved only from
complete sibling/table structure. These are explicit hypotheses, not proved
expression rewrites. Independent later keys validate the resulting states.
"""
from collections import Counter,defaultdict
from types import SimpleNamespace

from analyze_round_key_schedule import analyze


def check(trace,models,regular,key_callback=None):
    events=[event for event in trace.events if event['ordinal'] in regular]
    depth={};layers=defaultdict(list);seen=set();occurrences=0
    for event in events:
        occurrences+=1
        if occurrences>16 and event['variable'] in seen:continue
        if any(variable not in depth for variable in event['dependencies']):
            return dict(status='unresolved frontier parents',key_bytes_written=0)
        prior={depth[variable] for variable in event['dependencies']}
        level=max(prior)+1 if prior else 0
        depth[event['variable']]=level;seen.add(event['variable']);layers[level].append(event)
    if any(len(layers[level])!=16 for level in range(len(layers))):
        return dict(status='frontier layer shape rejected',key_bytes_written=0)
    projected=[];removed=repairs=0
    for level in range(len(layers)):
        current=layers[level]
        if not level:
            if any(event['dependencies'] for event in current):return dict(status='noninitial first frontier',key_bytes_written=0)
            projected.extend(dict(event,dependencies=set()) for event in current);continue
        previous={event['variable'] for event in layers[level-1]}
        selected=[set(event['dependencies'])&previous for event in current]
        groups={tuple(sorted(group)) for group in selected if len(group)==4}
        if len(groups)!=4 or set().union(*(set(group) for group in groups))!=previous:
            return dict(status='frontier column shape rejected',level=level,key_bytes_written=0)
        filled={group:{current[index]['ordinal'] for index,values in enumerate(selected) if tuple(sorted(values))==group} for group in groups}
        for index,values in enumerate(selected):
            if len(values)==4:continue
            choices=[group for group in groups if set(group)<=values and current[index]['ordinal'] not in filled[group]]
            if len(choices)!=1:
                return dict(status='ambiguous frontier union unresolved',level=level,key_bytes_written=0)
            group=choices[0];selected[index]=set(group);filled[group].add(current[index]['ordinal']);repairs+=1
        counts=Counter(tuple(sorted(values)) for values in selected)
        if any(count!=4 for count in counts.values()) or any(filled[group]!=set(regular) for group in groups):
            return dict(status='frontier sibling/table shape rejected',level=level,key_bytes_written=0)
        for event,values in zip(current,selected):
            removed+=len(set(event['dependencies'])-values)
            projected.append(dict(event,dependencies=values))
    result=analyze(SimpleNamespace(events=projected),models,regular,key_callback)
    return dict(status='nearest-round frontier hypothesis checked',frontier_layers=len(layers),
        projected_dependency_edges=removed,resolved_union_events=repairs,schedule=result,key_bytes_written=0,
        scope='dependency depth groups observed lookups; projects older edges and resolves unions from complete table/sibling patterns, then independently checks later AES keys; no semantic proof of removed edges, final round, table initialization or native-auth claim')
