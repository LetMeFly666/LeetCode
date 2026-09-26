'''
Author: LetMeFly
Date: 2026-04-04 13:57:29
LastEditors: LetMeFly.xyz
LastEditTime: 2026-04-04 14:10:12
'''
from typing import List

class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        sx, sy = startPos
        ex, ey = homePos
        return sum(rowCosts[min(sx, ex) : max(sx, ex) + 1]) + sum(colCosts[min(sy, ey) : max(sy, ey) + 1]) - rowCosts[sx] - colCosts[sy]