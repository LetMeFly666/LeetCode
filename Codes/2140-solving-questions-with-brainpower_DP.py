'''
Author: LetMeFly
Date: 2025-04-03 23:48:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-03 23:49:25
'''
from typing import List

class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            j = min(i + questions[i][1] + 1, n)
            dp[i] = max(dp[i + 1], dp[j] + questions[i][0])
        return dp[0]