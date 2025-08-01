'''
Author: LetMeFly
Date: 2025-08-01 18:48:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-01 18:54:38
'''
import os
os.popen('sleep 5 && echo hello >> testSubCMD.txt')
# 结论：主线程结束后，过几秒testSubCMD.txt是会新增一行hello的

os.popen('./testSubCMD.sh')

import subprocess
subprocess.Popen(['sh', './testSubCMD.sh'])
