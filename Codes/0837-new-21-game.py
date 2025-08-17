'''
Author: LetMeFly
Date: 2025-08-17 19:33:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-17 19:40:07
'''
class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        dp = [0.] * (k + maxPts)
        s = 0.
        for i in range(k, k + maxPts):
            dp[i] = 1. if i <= n else 0.
            s += dp[i]
        for i in range(k - 1, -1, -1):
            dp[i] = s / maxPts
            s = s + dp[i] - dp[i + maxPts]
        return dp[0]