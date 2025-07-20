'''
Author: LetMeFly
Date: 2025-07-18 22:33:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-20 22:23:43
'''
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[0] * k for _ in range(k)]
        for x in nums:
            x %= k
            for y in range(k):
                dp[y][x] = dp[x][y] + 1
        return max(map(max, dp))