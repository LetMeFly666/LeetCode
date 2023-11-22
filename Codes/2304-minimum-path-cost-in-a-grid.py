'''
Author: LetMeFly
Date: 2023-11-22 21:03:16
LastEditors: LetMeFly
LastEditTime: 2023-11-22 21:07:24
'''
from typing import List

class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        for i in range(n - 2, -1, -1):
            for j in range(m):
                m_ = 100000000
                for k in range(m):
                    m_ = min(m, grid[i + 1][k] + moveCost[grid[i][j]][k])
                grid[i][j] += m_
        print(grid)
        return min(grid[0])
