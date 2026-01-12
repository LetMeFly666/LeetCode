'''
Author: LetMeFly
Date: 2026-01-12 13:11:20
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-12 13:12:26
'''
import json

input_file = "LastModifiedTime.json"
output_file = input_file

with open(input_file, "r", encoding="utf-8") as f:
    data = json.load(f)

sorted_data = dict(sorted(data.items(), key=lambda x: x[0]))

with open(output_file, "w", encoding="utf-8") as f:
    json.dump(sorted_data, f, ensure_ascii=False, indent=4)
