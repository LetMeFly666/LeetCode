'''
Author: LetMeFly
Date: 2025-03-14 10:18:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-14 10:25:09
Description: https://github.com/LetMeFly666/LeetCode/issues/811
'''
import subprocess
import json
import sys


def getPrOrIssueMaxNum(prOrIssue: str) -> int:
    print(f'max {prOrIssue} number:', end=' ')
    sys.stdout.flush()
    cmd = ['gh', prOrIssue, 'list', '--state', 'all', '--limit', '1', '--json', 'number']
    result = subprocess.run(cmd, capture_output=True, text=True, check=True)
    data = json.loads(result.stdout)
    print(data)
    return data[0]['number']

lastNum = max(getPrOrIssueMaxNum('pr'), getPrOrIssueMaxNum('issue'))
print(lastNum)