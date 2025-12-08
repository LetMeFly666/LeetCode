'''
Author: LetMeFly
Date: 2025-12-08 21:36:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-08 22:10:16
'''
import os
import json
import tqdm
os.chdir(os.path.dirname(os.path.abspath(__file__)))


# titleSlug -> (num, name)
# 如: two-sum -> (1, 1.两数之和)
data = {}
for file in tqdm.tqdm(os.listdir('.')):
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
with open('_map_slug+num+name.json', 'w', encoding='utf-8') as f:
    json.dump(data, f, ensure_ascii=False)
"""
Run result:
100%|█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████| 4004/4004 [00:00<00:00, 4547.02it/s]
"""