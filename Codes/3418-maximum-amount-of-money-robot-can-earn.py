'''
Author: LetMeFly
Date: 2026-04-04 14:12:53
LastEditors: LetMeFly.xyz
LastEditTime: 2026-04-04 14:23:48
'''
from typing import List
from math import inf

class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        n, m = len(coins), len(coins[0])
        dp = [[[-inf for _ in range(m)] for _ in range(n)] for _ in range(3)]
        dp[0][0][0] = coins[0][0]
        dp[1][0][0] = dp[2][0][0] = max(coins[0][0], 0)

        for i in range(n):
            for j in range(m):
                if not i and not j:
                    continue
                for th in range(3):
                    dp[th][i][j] = max(dp[th][i - 1][j] if i else -inf, dp[th][i][j - 1] if j else -inf) + coins[i][j]
                for th in range(1, 3):
                    dp[th][i][j] = max(dp[th][i][j], dp[th - 1][i - 1][j] if i else -inf, dp[th - 1][i][j - 1] if j else -inf)
        
        return dp[2][n - 1][m - 1]
