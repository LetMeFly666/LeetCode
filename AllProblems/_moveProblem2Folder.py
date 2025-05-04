'''
Author: LetMeFly
Date: 2025-05-04 21:10:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-04 21:24:45
'''
import os
import shutil
import time


start = time.time()
BASE_DIR = 'AllProblems'

for file in os.listdir(BASE_DIR):
    name = os.path.join(BASE_DIR, file)
    if not name.endswith('.md'):
        continue
    prefix = name[:-3]
    if not os.path.exists(prefix):
        os.mkdir(prefix)
    newName = os.path.join(prefix, file)
    shutil.move(name, newName)
    print(newName)

end = time.time()
print(end - start)