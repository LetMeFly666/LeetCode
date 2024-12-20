'''
Author: LetMeFly
Date: 2024-12-20 21:38:56
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-20 21:43:34
'''
from math import sqrt

M, Mi = 0, 0

def getYin(n: int) -> int:
    k = int(sqrt(n))
    ans = 0
    for i in range(1, k):
        if n % i == 0:
            ans += 2
    if k * k == n:
        ans += 1
    return ans

for n in range(1, 100001):
    yinN = getYin(n)
    if yinN > M:
        M, Mi = yinN, n
print(f'{Mi} 因子数最多，为{M}个')