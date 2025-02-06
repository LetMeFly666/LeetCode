'''
Author: LetMeFly
Date: 2025-02-06 13:55:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-06 13:56:30
'''
from typing import List
from itertools import permutations

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        return list(set(permutations(nums)))