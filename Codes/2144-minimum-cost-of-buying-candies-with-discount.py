'''
Author: LetMeFly
Date: 2026-06-01 22:06:51
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-01 22:13:03
'''
from typing import List

class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse=True)
        return sum(cost) - sum(cost[2::3])
