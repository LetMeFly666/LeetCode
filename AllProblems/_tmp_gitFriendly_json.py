'''
Author: LetMeFly
Date: 2026-06-14 12:57:25
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-14 13:04:23
'''
import json

with open('AllProblems/_map_slug+num+name.json', 'r', encoding='utf-8') as f:
    data = f.read()
obj: dict = json.loads(data)
formatted = (
    "{\n"
    + ",\n".join(
        f'{json.dumps(k, ensure_ascii=False)}: '
        f'{json.dumps(v, ensure_ascii=False)}'
        for k, v in obj.items()
    )
    + "\n}\n"
)
with open('AllProblems/_map_slug+num+name.json', 'w', encoding='utf-8') as f:
    f.write(formatted)
