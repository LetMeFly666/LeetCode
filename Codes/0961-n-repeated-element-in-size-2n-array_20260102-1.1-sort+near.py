'''
Author: LetMeFly
Date: 2026-01-02 12:47:42
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-02 14:48:48
'''
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return nums[i]