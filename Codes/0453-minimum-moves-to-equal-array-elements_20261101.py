'''
Author: LetMeFly
Date: 2026-11-01 10:57:43
LastEditors: LetMeFly.xyz
LastEditTime: 2026-11-01 11:00:17
'''
from typing import List

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        m = min(nums)
        return sum(t - m for t in nums)
