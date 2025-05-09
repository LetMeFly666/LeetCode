'''
Author: LetMeFly
Date: 2025-05-09 12:46:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-09 12:57:20
'''
import os

BASE_DIR = 'AllProblems'

def filter1file(file: str):
    splited = file.split('.')
    for i in splited:
        if i.endswith(' '):
            print(file)

for dir in os.listdir(BASE_DIR):
    dir_path = os.path.join(BASE_DIR, dir)
    if os.path.isfile(dir_path):
        filter1file(dir_path)
        continue
    for file in os.listdir(dir_path):
        file_path = os.path.join(dir_path, file)
        filter1file(file_path)