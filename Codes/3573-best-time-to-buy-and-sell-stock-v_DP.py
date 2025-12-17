'''
Author: LetMeFly
Date: 2025-12-17 23:43:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-17 23:51:56
'''
from typing import List
from math import inf

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)

        # dp[i][j][status]: i有效范围0~n-1，j有效范围0~k，这俩都多开一个无效状态的空间
        dp = [[[-inf] * 3 for _ in range(k + 2)] for _ in range(n + 1)]
        for j in range(1, k + 2):
            dp[0][j][0] = 0

        for i, price in enumerate(prices):
            for j in range(1, k + 2):
                dp[i+1][j][0] = max(dp[i][j][0], dp[i][j][1] + price, dp[i][j][2] - price)
                dp[i+1][j][1] = max(dp[i][j][1], dp[i][j-1][0] - price)
                dp[i+1][j][2] = max(dp[i][j][2], dp[i][j-1][0] + price)
        return dp[-1][-1][0]