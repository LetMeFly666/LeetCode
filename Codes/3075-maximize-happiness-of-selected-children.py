'''
Author: LetMeFly
Date: 2025-12-25 12:56:03
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-25 13:02:05
'''
from typing import List

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        return sum(max(0, h - i) for i, h in enumerate(sorted(happiness, reverse=True)[:k]))