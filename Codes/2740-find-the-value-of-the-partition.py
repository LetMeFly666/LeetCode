'''
Author: LetMeFly
Date: 2024-07-26 15:20:52
LastEditors: LetMeFly
LastEditTime: 2024-07-26 15:22:06
'''
from typing import List

class Solution:
    def findValueOfPartition(self, nums: List[int]) -> int:
        nums.sort()
        return min(abs(nums[i] - nums[i - 1]) for i in range(1, len(nums)))