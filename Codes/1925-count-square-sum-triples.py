'''
Author: LetMeFly
Date: 2025-12-08 18:40:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-08 18:49:37
'''
from math import sqrt

class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                k = a * a + b * b
                c = sqrt(k)
                ans += c <= n and c * c == k
        return ans