'''
Author: LetMeFly
Date: 2025-08-22 21:18:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-22 21:23:44
'''
from typing import List

class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        l = u = 1000
        r = d = 0
        for i, line in enumerate(grid):
            for j, g in enumerate(line):
                if g:
                    l = min(l, j)
                    r = max(r, j)
                    u = min(u, i)
                    d = max(d, i)
        return (r - l + 1) * (d - u + 1)