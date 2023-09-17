'''
Author: LetMeFly
Date: 2023-09-17 15:56:54
LastEditors: LetMeFly
LastEditTime: 2023-09-17 16:05:05
'''
from typing import List

class Solution:
    def realRob(self, nums: List[int], l: int, r: int) -> int:
        lastRob, lastNot = nums[l], 0
        for i in range(l + 1, r):
            lastRob, lastNot = lastNot + nums[i], max(lastNot, lastRob)
        return max(lastRob, lastNot)

    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        return max(self.realRob(nums, 0, len(nums) - 1), self.realRob(nums, 1, len(nums)))