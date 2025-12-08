'''
Author: LetMeFly
Date: 2025-12-08 18:40:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-08 18:53:01
'''
from math import sqrt

class Solution:
    def countTriples(self, n: int) -> int:
        ans = 0
        for a in range(1, n + 1):
            for b in range(1, n + 1):
                k = a * a + b * b
                c = int(sqrt(k))
                ans += c <= n and c * c == k
                # if c <= n and c * c == k:
                #     print(f"({a}, {b}, {c})")
        return ans

# a = Solution()
# print(a.countTriples(5))