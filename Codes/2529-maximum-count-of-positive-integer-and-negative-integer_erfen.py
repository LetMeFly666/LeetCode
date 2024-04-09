'''
Author: LetMeFly
Date: 2024-04-09 15:15:37
LastEditors: LetMeFly
LastEditTime: 2024-04-09 15:17:08
'''
from typing import List
from bisect import bisect_left, bisect_right

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        return max(bisect_left(nums, 0), len(nums) - bisect_right(nums, 0))