'''
Author: LetMeFly
Date: 2025-04-09 22:31:45
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-09 23:22:07
'''
import os
num = 3375
title = "使数组的值全部为 K 的最少操作次数"
issueNum = 860
lastSHA = '62e66ae8686379cd05999ea9838b25765d4df82b'
def getPlatform():
    return 'MacOS.Manual'

cmd = f'gh pr create -H {num} -t "添加问题“{num}.{title}”的代码和题解" -b "By [newSolution.py](https://github.com/LetMeFly666/LeetCode/blob/{lastSHA}/newSolution.py) using GH on {getPlatform()} | close: #{issueNum}" -l "题解" -a "@me"'
print(cmd)
prResult = os.popen(cmd).read()
print(prResult)
prNumber = int(prResult.split('/')[-1])
print(prNumber)