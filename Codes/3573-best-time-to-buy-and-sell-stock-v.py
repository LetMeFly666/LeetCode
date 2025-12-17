'''
Author: LetMeFly
Date: 2025-12-17 23:10:13
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-17 23:14:05
'''
from typing import List
from functools import cache
from math import inf

class Solution:
    def maximumProfit(self, prices: List[int], k: int) -> int:
        n = len(prices)

        @cache
        def dfs(i: int, j: int, status: int) -> int:
            """0无1有2空头"""

            if j < 0:
                return -inf
            if i < 0:
                return -inf if status else 0
            
            if status == 0:
                return max(dfs(i - 1, j, 0), dfs(i - 1, j, 1) + prices[i], dfs(i - 1, j, 2) - prices[i])
            elif status == 1:
                return max(dfs(i - 1, j, 1), dfs(i - 1, j - 1, 0) - prices[i])
            else:
                return max(dfs(i - 1, j, 2), dfs(i - 1, j - 1, 0) + prices[i])

        return dfs(n - 1, k, 0)