'''
Author: LetMeFly
Date: 2024-03-01 20:03:51
LastEditors: LetMeFly
LastEditTime: 2024-03-01 20:05:57
'''
from typing import List

class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        dp = [False] * (len(nums) + 1)
        dp[0] = True
        for i in range(len(nums)):
            if i + 1 - 2 >= 0 and dp[i + 1 - 2] and nums[i] == nums[i - 1]:
                dp[i + 1] = True
            if i + 1 - 3 >= 0 and dp[i + 1 - 3] and (nums[i] == nums[i - 1] == nums[i - 2] or nums[i] == nums[i - 1] + 1 == nums[i - 2] + 2):
                dp[i + 1] = True
        return dp[-1]