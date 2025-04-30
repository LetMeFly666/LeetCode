'''
Author: LetMeFly
Date: 2025-04-30 17:24:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-30 17:26:24
'''
from typing import List

class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(len(str(t)) % 2 == 0 for t in nums)