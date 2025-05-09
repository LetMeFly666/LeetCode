'''
Author: LetMeFly
Date: 2025-05-09 12:46:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-09 13:03:25
'''
import os

BASE_DIR = 'AllProblems'

def check1(file: str, split_str: str):
    splited = file.split(split_str)
    notOk = False
    for i, d in enumerate(splited):
        if d.endswith(' '):
            splited[i] = d.strip()
            notOk = True
    if notOk:
        return split_str.join(splited)
    return False

def filter1file(file: str):
    split_char_list = ['.', '/']
    now = file
    for split_char in split_char_list:
        result = check1(now, split_char)
        if result:
            now = result
    if now != file:
        print(f'{file} -> {now}')

for dir in os.listdir(BASE_DIR):
    dir_path = os.path.join(BASE_DIR, dir)
    if os.path.isfile(dir_path):
        filter1file(dir_path)
        continue
    for file in os.listdir(dir_path):
        file_path = os.path.join(dir_path, file)
        filter1file(file_path)