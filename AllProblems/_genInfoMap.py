'''
Author: LetMeFly
Date: 2025-12-08 21:36:58
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-14 13:21:26
'''
import os
import json
os.chdir(os.path.dirname(os.path.abspath(__file__)))


# titleSlug -> (num, name)
# 如: two-sum -> (1, 1.两数之和)
data = {}
for file in os.listdir('.'):
    if not os.path.isdir(file):
        continue
    name = file
    num = name.split('.')[0]
    try:
        with open(os.path.join(file, 'titleSlug.txt'), 'r', encoding='utf-8') as f:
            titleSlug = f.read().strip()
    except:
        continue
    data[titleSlug] = (num, name)
formatted = (
    "{\n"
    + ",\n".join(
        f'{json.dumps(k, ensure_ascii=False)}: '
        f'{json.dumps(v, ensure_ascii=False)}'
        for k, v in sorted(
            data.items(),
            key=lambda kv: kv[1][0],
        )
    )
    + "\n}\n"
)
with open('_map_slug+num+name.json', 'w', encoding='utf-8') as f:
    f.write(formatted)
"""
Run result:
100%|█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████| 4255/4255 [00:00<00:00, 13298.05it/s]
"""
