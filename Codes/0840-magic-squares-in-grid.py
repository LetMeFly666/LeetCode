'''
Author: LetMeFly
Date: 2025-12-30 13:14:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-30 13:38:58
'''
from typing import List

class Solution:
    def ok(self, grid: List[List[int]], i: int, j: int) -> bool:
        mask = 0
        colCnt = [0] * 3
        rowCnt = [0] * 3
        for di in range(3):
            for dj in range(3):
                v = grid[i - di][j - dj]
                mask |= 1 << v
                rowCnt[di] += v
                colCnt[dj] += v
        if mask != (1 << 10) - 2:
            return False
        cnt = grid[i][j] + grid[i - 1][j - 1] + grid[i - 2][j - 2]
        if grid[i - 2][j] + grid[i - 1][j - 1] + grid[i][j - 2] != cnt:
            return False
        if any(c != cnt for c in colCnt):
            return False
        if any(r != cnt for r in rowCnt):
            return False
        return True
    
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        return sum(self.ok(grid, i, j) for j in range(2, len(grid[0])) for i in range(2, len(grid)))