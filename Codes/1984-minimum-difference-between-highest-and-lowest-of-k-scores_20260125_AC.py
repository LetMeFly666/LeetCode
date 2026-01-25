'''
Author: LetMeFly
Date: 2026-01-25 10:32:52
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-25 10:37:04
'''
from typing import List

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return min(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))