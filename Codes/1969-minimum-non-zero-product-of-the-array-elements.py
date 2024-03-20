'''
Author: LetMeFly
Date: 2024-03-20 11:02:25
LastEditors: LetMeFly
LastEditTime: 2024-03-20 11:05:11
'''
MOD = int(1e9) + 7

class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        return ((1 << p) - 1) * pow((1 << p) - 2, ((1 << p) - 2) // 2, MOD) % MOD  # 记得是//而不是/