'''
Author: LetMeFly
Date: 2024-04-12 13:45:59
LastEditors: LetMeFly
LastEditTime: 2024-04-12 13:47:07
'''
from typing import List

class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        n = len(grid)
        for j in range(n):
            ok = True
            for i in range(n):
                if grid[i][j]:
                    ok = False
                    break
            if ok:
                return j
        return -1  # Fake Return