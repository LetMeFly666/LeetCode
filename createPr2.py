'''
Author: LetMeFly
Date: 2025-12-25 22:00:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-25 22:08:58
'''
import subprocess

num = 3075
gitCommitMsgPrefix = 'test'

cmd = [
    'gh', 'pr', 'create',
    # '-H', num,  # Cannot
    '-H', f'{num}',  # -H branch可能是 新版/旧版/Mac 所需的属性，并没有默认使用当前分支诶
    '-B', 'dev',
    '-t', gitCommitMsgPrefix,
    '-b', f'By [newSolution.py](https://github.com/LetMeFly666/LeetCode/blob/{1}/newSolution.py) using GH on {1} | close: #{1279}',
    "-l", "题解",
    "-a", "@me",
]
print(cmd)
prResult = subprocess.run(
    cmd,
    capture_output=True,
    text=True
)
if prResult.returncode:
    prAlreadyExists = True
    prResult = prResult.stderr
else:
    prAlreadyExists = False
    prResult = prResult.stdout
print('*' * 50)
print(prResult)
print('*' * 50)
prNumber = int(prResult.split('/')[-1])
print(prNumber)
if prAlreadyExists:
    cmd = ['gh', 'pr', 'comment', str(prNumber), '-b', 'Hello, we meet again.']
    subprocess.run(cmd)