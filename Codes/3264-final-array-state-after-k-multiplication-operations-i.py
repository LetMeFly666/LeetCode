'''
Author: LetMeFly
Date: 2024-12-13 09:34:55
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-13 09:36:26
'''
from typing import List

class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            m, loc = nums[0], 0
            for i, val in enumerate(nums):
                if val < m:
                    m, loc = val, i
            nums[loc] *= multiplier
        return nums