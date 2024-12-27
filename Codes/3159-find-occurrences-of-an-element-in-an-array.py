'''
Author: LetMeFly
Date: 2024-12-27 12:16:30
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-27 12:18:08
'''
from typing import List

class Solution:
    def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
        locs = [i for i in range(len(nums)) if nums[i] == x]
        return [-1 if q > len(locs) else locs[q - 1] for q in queries]