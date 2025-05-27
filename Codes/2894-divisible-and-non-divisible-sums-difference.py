'''
Author: LetMeFly
Date: 2025-05-27 21:42:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-27 21:54:46
'''
class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        return (1 + n) * n // 2 - (m + n // m * m) * (n // m)