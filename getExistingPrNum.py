'''
Author: LetMeFly
Date: 2026-02-15 14:47:33
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-15 14:52:26
'''
import subprocess
import json

num = '67'

opening_pr_json = subprocess.run([
    'gh', 'pr', 'list',
    '--state', 'open',
    '--json', 'number,url,headRefName,headRepository'
], capture_output=True, text=True).stdout.strip()
opening_pr_json = json.loads(opening_pr_json)
for pr in opening_pr_json:
    if pr['headRefName'] == num:
        prNumber = int(pr['number'])
    break
print(prNumber)