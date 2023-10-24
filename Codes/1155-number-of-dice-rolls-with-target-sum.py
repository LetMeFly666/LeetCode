'''
Author: LetMeFly
Date: 2023-10-24 22:54:13
LastEditors: LetMeFly
LastEditTime: 2023-10-24 22:56:19
'''
MOD = int(1e9 + 7)
class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        dp = [1] + [0] * target
        for i in range(1, n + 1):
            for j in range(target, -1, -1):
                dp[j] = 0
                for _k in range(1, min(k + 1, j + 1)):
                    dp[j] = (dp[j] + dp[j - _k]) % MOD
        return dp[-1]