'''
Author: LetMeFly
Date: 2026-04-04 13:57:29
LastEditors: LetMeFly.xyz
LastEditTime: 2026-04-04 14:09:01
'''
from typing import List

class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        sx, sy = startPos
        hx, hy = homePos
        return sum(rowCosts[sx : hx + 1]) + sum(colCosts[sy : hy + 1]) -rowCosts[sx] - colCosts[sy]