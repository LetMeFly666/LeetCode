'''
Author: LetMeFly
Date: 2025-08-05 22:31:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-05 22:32:59
'''
import sys
import time

time.sleep(5)
with open('ff', 'a', encoding='utf-8') as f:
    f.write(f'{sys.argv}\n')