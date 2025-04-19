'''
Author: LetMeFly
Date: 2025-04-19 16:13:37
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-19 16:23:38
'''
from typing import List
from bisect import bisect_left, bisect_right


class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        return sum(bisect_right(nums, upper - nums[i], i + 1) - bisect_left(nums, lower - nums[i], i + 1) for i in range(len(nums)))