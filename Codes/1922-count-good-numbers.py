'''
Author: LetMeFly
Date: 2025-04-13 17:06:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-13 17:06:17
'''
MOD = 1000000007

class Solution:
    def countGoodNumbers(self, n: int) -> int:
        return pow(5, (n + 1) // 2, MOD) * pow(4, n // 2, MOD) % MOD