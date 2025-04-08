'''
Author: LetMeFly
Date: 2025-04-08 23:47:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-08 23:54:23
'''
import os

cmd = 'gh pr create -H 3396 -t "添加问题3360的代码和题解 + 更新题库" -b "close: #858" -l "题解" -a "@me"'
prResult = os.popen(cmd).read()
print(prResult)
prNumber = int(prResult.split('/')[-1])

print(prNumber)