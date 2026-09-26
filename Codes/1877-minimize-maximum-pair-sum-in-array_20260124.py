'''
Author: LetMeFly
Date: 2026-01-24 09:29:52
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-24 09:36:17
'''
from typing import List

class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return max(nums[i] + nums[~i] for i in range(len(nums) // 2))