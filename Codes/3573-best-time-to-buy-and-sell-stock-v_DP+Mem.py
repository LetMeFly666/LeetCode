'''
Author: LetMeFly
Date: 2025-12-17 23:57:37
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-17 23:58:31
'''
from typing import List
from math import inf

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)

        # dp[i][j][status]: i有效范围0~n-1，j有效范围0~k，这俩都多开一个无效状态的空间
        dp = [[-inf] * 3 for _ in range(k + 2)]
        for j in range(1, k + 2):
            dp[j][0] = 0

        for i, price in enumerate(prices):
            for j in range(k + 1, 0, -1):
                dp[j][0] = max(dp[j][0], dp[j][1] + price, dp[j][2] - price)
                dp[j][1] = max(dp[j][1], dp[j-1][0] - price)
                dp[j][2] = max(dp[j][2], dp[j-1][0] + price)
        return dp[-1][0]