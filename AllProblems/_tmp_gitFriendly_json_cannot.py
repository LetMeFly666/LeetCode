'''
Author: LetMeFly
Date: 2026-06-14 12:57:25
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-14 12:58:42
'''
import json

with open('AllProblems/_map_slug+num+name.json', 'r', encoding='utf-8') as f:
    data = f.read()

with open("AllProblems/_map_slug+num+name.json", "w", encoding="utf-8") as f:
    json.dump( data, f, ensure_ascii=False, separators=(", ", ": "), indent=None)
