'''
Author: LetMeFly
Date: 2025-05-04 22:46:02
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-04 22:48:37
'''
def add(a, b):
    return a + b

def pingfang(a):
    return a * a

def jihuo(a):
    if a < 0:
        return 0
    else:
        return 1

print(add(1, 2))
print(pingfang(2))
print(jihuo(-100))
print(jihuo(3))