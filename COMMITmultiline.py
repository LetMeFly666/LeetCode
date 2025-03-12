'''
Author: LetMeFly
Date: 2025-03-11 14:35:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-11 14:35:27
'''
'''
Author: LetMeFly
Date: 2025-03-11 14:23:47
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-11 14:33:39
'''
import os
import subprocess
commitMsg = "2s2d323\nsf\nf3"
os.system('git add .')
subprocess.run(['git', 'commit', '-s', '-m', commitMsg])

"""
import os
commitMsg = "f\n2\n3"
os.system('git add .')
os.system(f'git commit -s -m "{commitMsg}"')

执行这段代码执行结果的commit msg只会是f而无法添加下面的行
"""