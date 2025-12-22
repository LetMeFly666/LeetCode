'''
Author: LetMeFly
Date: 2025-12-22 22:28:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-22 22:49:18
'''
from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        m = len(strs[0])
        dp = [0] * m
        for cur in range(m):
            for prev in range(cur):
                if dp[cur] < dp[prev] and all(s[prev] <= s[cur] for s in strs):
                    dp[cur] = dp[prev]
            dp[cur] += 1
        return m - max(dp)