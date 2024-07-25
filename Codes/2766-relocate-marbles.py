'''
Author: LetMeFly
Date: 2024-07-25 12:43:38
LastEditors: LetMeFly
LastEditTime: 2024-07-25 12:43:57
'''
from typing import List

class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        se = set(nums)
        for from_, to in zip(moveFrom, moveTo):
            se.remove(from_)
            se.add(to)
        return sorted(se)