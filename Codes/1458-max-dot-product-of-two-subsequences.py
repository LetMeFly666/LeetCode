'''
Author: LetMeFly
Date: 2026-01-08 09:21:01
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-08 09:29:41
'''
from typing import List

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [[-1000000000] * (len(nums2) + 1) for _ in range(len(nums1) + 1)]
        for i, x in enumerate(nums1, 1):
            for j, y in enumerate(nums2, 1):
                dp[i][j] = max(x * y, dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + x * y)
        return dp[-1][-1]