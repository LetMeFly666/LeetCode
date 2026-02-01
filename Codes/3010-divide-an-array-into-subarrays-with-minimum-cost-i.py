'''
Author: LetMeFly
Date: 2026-02-01 09:49:37
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-01 10:06:51
'''
from typing import List

class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        return nums[0] + sum(sorted(nums[1:])[:2])