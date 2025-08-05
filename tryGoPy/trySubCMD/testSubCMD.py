'''
Author: LetMeFly
Date: 2025-08-01 18:48:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-05 22:35:52
'''
import os
os.popen('python writer.py os.popen')
# 结论：主线程结束后，过几秒testSubCMD.txt是会新增一行hello的

# os.popen('testSubCMD.bat')

import subprocess
subprocess.Popen(['python', 'writer.py', 'subprocess.Popen and space test'])
