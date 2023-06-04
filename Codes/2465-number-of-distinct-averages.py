'''
Author: LetMeFly
Date: 2023-06-04 22:13:36
LastEditors: LetMeFly
LastEditTime: 2023-06-04 22:16:45
'''
from typing import List

class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums.sort()
        se = set()
        l, r = 0, len(nums) - 1
        while l < r:
            se.add(nums[l] + nums[r])
            l += 1
            r -= 1
        return len(se)
