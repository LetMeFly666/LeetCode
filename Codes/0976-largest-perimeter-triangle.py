'''
Author: LetMeFly
Date: 2025-09-28 13:21:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-28 13:30:31
'''
from typing import List

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums) - 3, -1, -1):
            if nums[i] + nums[i + 1] > nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0