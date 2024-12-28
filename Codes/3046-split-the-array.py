'''
Author: LetMeFly
Date: 2024-12-28 14:40:34
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-28 14:41:10
'''
from typing import List
from collections import Counter

class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        return max(Counter(nums).values()) <= 2