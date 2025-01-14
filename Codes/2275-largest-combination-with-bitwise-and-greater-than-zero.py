'''
Author: LetMeFly
Date: 2025-01-14 17:13:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-14 17:15:52
'''
from typing import List

class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        return max(sum(t >> i & 1 for t in candidates) for i in range(24))