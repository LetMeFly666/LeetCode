'''
Author: LetMeFly
Date: 2025-05-05 21:58:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-05 22:25:56
'''
MOD = 1000000007

class Solution:
    def numTilings(self, n: int) -> int:
        if n == 1:
            return 1
        dp = [0] * (n + 1)
        dp[0] = dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD
        return dp[-1]