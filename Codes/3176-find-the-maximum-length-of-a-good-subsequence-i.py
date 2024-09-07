'''
Author: LetMeFly
Date: 2024-09-07 10:48:28
LastEditors: LetMeFly
LastEditTime: 2024-09-07 10:57:16
'''
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[-1] * (k + 1) for _ in range(len(nums))]
        for i in range(len(nums)):
            dp[i][0] = 1
            for l in range(k + 1):
                for j in range(i):
                    diff = int(nums[i] != nums[j])
                    if l - diff >= 0:
                        dp[i][l] = max(dp[i][l], dp[j][l - diff] + 1)
        return max(max(dp[i]) for i in range(len(nums)))