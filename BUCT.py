'''
Author: LetMeFly
Date: 2023-05-10 16:26:51
LastEditors: LetMeFly
LastEditTime: 2023-05-10 16:56:18
'''
T = int(input())
for _CASE in range(T):
    s = input()
    locMul = s.find('*')
    originalVal = int(s[:locMul]) * int(s[locMul + 1:])
    pureNum = s[:locMul] + s[locMul + 1:]
    can = False
    for loc in range(1, len(pureNum)):
        if loc == locMul:
            continue
        if int(pureNum[:loc]) * int(pureNum[loc:]) == originalVal:
            can = True
            break
    print('Yes' if can else 'No')