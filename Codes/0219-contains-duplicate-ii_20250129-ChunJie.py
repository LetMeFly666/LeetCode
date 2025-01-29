'''
Author: LetMeFly
Date: 2025-01-29 11:51:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-29 11:51:09
'''
from typing import List

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        ma = dict()
        for i, t in enumerate(nums):
            if t in ma and i - ma[t] <= k:
                return True
            ma[t] = i
        return False