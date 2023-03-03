'''
Author: LetMeFly
Date: 2023-02-24 11:15:31
LastEditors: LetMeFly
LastEditTime: 2023-03-03 19:18:08
'''
T = int(input())
for _CASE in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    for i in a:
        print(i, end=' ')
    print()