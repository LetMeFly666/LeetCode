'''
Author: LetMeFly
Date: 2024-07-08 13:17:16
LastEditors: LetMeFly
LastEditTime: 2024-07-08 13:18:26
'''
from typing import List

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        sum_ =sum(nums)
        nowSum = 0
        for i in range(len(nums)):
            if sum_ - nums[i] == nowSum * 2:
                return i
            nowSum += nums[i]
        return -1