'''
Author: LetMeFly
Date: 2024-04-22 10:07:09
LastEditors: LetMeFly
LastEditTime: 2024-04-22 10:08:32
'''
from typing import List

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0] * (target + 1)
        dp[0] = 1
        for i in range(1, target + 1):
            for num in nums:
                if num <= i:
                    dp[i] += dp[i - num]
        return dp[target]