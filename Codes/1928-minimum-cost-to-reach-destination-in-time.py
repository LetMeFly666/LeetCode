'''
Author: LetMeFly
Date: 2024-10-03 12:52:33
LastEditors: LetMeFly
LastEditTime: 2024-10-03 12:55:56
'''
from typing import List

class Solution:
    def minCost(self, maxTime: int, edges: List[List[int]], passingFees: List[int]) -> int:
        dp = [[10000000] * len(passingFees) for _ in range(maxTime + 1)]
        dp[0][0] = passingFees[0]
        for t in range(1, maxTime + 1):
            for i, j, thisTime in edges:
                if thisTime <= t:
                    dp[t][j] = min(dp[t][j], dp[t - thisTime][i] + passingFees[j])
                    dp[t][i] = min(dp[t][i], dp[t - thisTime][j] + passingFees[i])
        ans = min(d[-1] for d in dp)
        return -1 if ans == 10000000 else ans