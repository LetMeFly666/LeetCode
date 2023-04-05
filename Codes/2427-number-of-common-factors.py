'''
Author: LetMeFly
Date: 2023-04-05 12:45:57
LastEditors: LetMeFly
LastEditTime: 2023-04-05 12:54:35
'''

if False:  # 方法一，枚举到min(a, b)
    class Solution:
        def commonFactors(self, a: int, b: int) -> int:
            return sum(a % i == 0 and b % i == 0 for i in range(1, min(a, b) + 1))


# 方法二，枚举到gcd(a, b)
from math import gcd, sqrt
class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        ans = 0
        c = gcd(a, b)
        for i in range(1, int(sqrt(c)) + 1):
            if c % i == 0:
                ans += 1
                if c // i != i:
                    ans += 1
        return ans