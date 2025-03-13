'''
Author: LetMeFly
Date: 2025-03-13 20:22:36
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-13 20:55:59
Description: #807 - 只能对所有没有categories的博客依据文件名前缀插入
'''
import os

parentDir = 'Solutions'

for file in os.listdir(parentDir):
    path = os.path.join(parentDir, file)
    if os.path.isdir(path):
        continue
    if file.startswith('Other'):
        toInsert = 'categories: [技术思考'
    else:
        toInsert = 'categories: [题解, '
    typeDict = {
        'AtCoder': 'AtCoder',
        'BUCT': '北化OJ',
        'Codeforces': 'Codeforces',
        'CSDN': 'CSDN周赛',
        'LeetCode': 'LeetCode',
        'MaTiJi': '马蹄集',
    }
    for key, val in typeDict.items():
        if file.startswith(key):
            toInsert += val
    toInsert += ']\n'
    print(path, toInsert)
    with open(path, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    lines.insert(4, toInsert)
    with open(path, 'w', encoding='utf-8') as f:
        f.writelines(lines)