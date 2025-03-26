'''
Author: LetMeFly
Date: 2025-03-26 13:45:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-26 13:47:07
'''
class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        to = min(n, k // 2)
        n -= to
        return to * (to + 1) // 2 + n * (k + k + n - 1) // 2