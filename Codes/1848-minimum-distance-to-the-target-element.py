'''
Author: LetMeFly
Date: 2026-04-13 21:39:33
LastEditors: LetMeFly.xyz
LastEditTime: 2026-04-13 21:41:57
'''
from typing import List

class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(i - start) for i, v in enumerate(nums) if v == target)
