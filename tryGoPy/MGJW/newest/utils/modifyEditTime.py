'''
Author: LetMeFly
Date: 2025-07-29 22:29:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-29 23:10:49
'''
import os
import sys
from datetime import datetime
import time

dirPath = sys.argv[1] if len(sys.argv) > 1 else input('修改哪个文件夹：')
newDate = datetime(2023, 1, 1, 12, 0, 0)
timeStamp = time.mktime(newDate.timetuple())

for file in os.listdir(dirPath):
    path = os.path.join(dirPath, file)
    os.utime(path, (timeStamp, timeStamp))
