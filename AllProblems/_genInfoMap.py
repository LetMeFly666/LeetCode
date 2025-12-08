import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))


# titleSlum -> (num, name)
# 如: two-sum -> (1, 1.两数之和)
data = {}
for file in os.listdir('.'):
    if not os.path.isdir(file):
        continue
    