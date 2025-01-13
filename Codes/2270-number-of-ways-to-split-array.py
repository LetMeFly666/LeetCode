'''
Author: LetMeFly
Date: 2025-01-13 22:32:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-13 22:33:53
'''
from typing import List

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        prefix = [0] * len(nums)
        prefix[0] = nums[0]
        for i in range(1, len(nums)):
            prefix[i] = prefix[i - 1] + nums[i]
        return sum(prefix[i] >= prefix[-1] - prefix[i] for i in range(len(nums) - 1))