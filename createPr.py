'''
Author: LetMeFly
Date: 2025-12-25 21:49:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-25 21:56:24
'''
import os

cmd = 'gh pr create -H 3075 -t "test" -b "test" -l "题解" -a "@me"'
"""
Warning: 2 uncommitted changes
a pull request for branch "3075" into branch "master" already exists:
https://github.com/LetMeFly666/LeetCode/pull/1280
**********

**********
Traceback (most recent call last):
  File "F:\OtherApps\Program\Git\Store\Store20_LeetCode\createPr.py", line 23, in <module>
    prNumber = int(prResult.split('/')[-1])
ValueError: invalid literal for int() with base 10: ''
"""
# cmd = 'gh pr create -H 3075 -B dev -t "test" -b "test" -l "题解" -a "@me"'
"""
Warning: 2 uncommitted changes
**********
https://github.com/LetMeFly666/LeetCode/pull/1281

**********
1281
"""
prResult = os.popen(cmd).read()
print('*' * 10)
print(prResult)
print('*' * 10)
prNumber = int(prResult.split('/')[-1])
print(prNumber)

"""
好家伙，原来pr已经存在的时候创建会失败，此时不是stdout，而是直接输出到了控制台
"""

