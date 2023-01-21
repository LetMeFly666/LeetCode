'''
Author: LetMeFly
Date: 2023-01-21 10:37:19
LastEditors: LetMeFly
LastEditTime: 2023-01-21 10:45:00
'''
from typing import List


class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        dp = [1, 0, 1]
        for i in range(1, len(obstacles)):
            minStep = 999999
            for j in range(3):
                if obstacles[i] == j + 1:
                    dp[j] = 999999
                else:
                    minStep = min(minStep, dp[j])
            for j in range(3):
                if obstacles[i] != j + 1:
                    dp[j] = min(dp[j], minStep + 1)
        return min(dp)