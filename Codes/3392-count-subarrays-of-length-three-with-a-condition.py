'''
Author: LetMeFly
Date: 2025-04-27 23:49:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-27 23:49:26
'''
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        return sum((nums[i - 2] + nums[i]) * 2 == nums[i - 1] for i in range(2, len(nums)))