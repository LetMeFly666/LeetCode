'''
Author: LetMeFly
Date: 2026-08-20 10:12:05
LastEditors: LetMeFly.xyz
LastEditTime: 2026-08-20 10:28:27
'''
from typing import List

class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        v1, v2 = [nums[0]], [nums[1]]
        for i in range(2, len(nums)):
            (v1 if v1[-1] > v2[-1] else v2).append(nums[i])
        return v1 + v2
