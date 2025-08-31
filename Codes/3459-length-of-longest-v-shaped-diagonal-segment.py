'''
Author: LetMeFly
Date: 2025-08-28 12:54:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-31 17:56:33
'''
from typing import List
from functools import cache

class Solution:
    directions = [
        [1, 1],
        [1, -1],
        [-1, -1],
        [-1, 1]
    ]

    """
    canContinue只考虑从(i, j)开始能否沿着方向d走一步
    """
    def canContinue(self, i: int, j: int, d: int) -> bool:
        ni, nj = i + self.directions[d][0], j + self.directions[d][1]
        if ni < 0 or ni >= self.n or nj < 0 or nj >= self.m:
            return False
        now = self.grid[i][j]
        next = self.grid[ni][nj]
        return now == 1 and next == 2 or now != 1 and next != 1 and now != next

    @cache
    def dfs(self, i: int, j: int, d: int, times: int) -> int:
        then = 0
        if self.canContinue(i, j, d):
            then = self.dfs(i + self.directions[d][0], j + self.directions[d][1], d, times)
        if times == 0:
            nd = (d + 1) % 4
            if self.canContinue(i, j, nd):
                then = max(then, self.dfs(i + self.directions[nd][0], j + self.directions[nd][1], nd, 1))
        return then + 1

    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.n, self.m = len(grid), len(grid[0])
        ans = 0
        for i, line in enumerate(grid):
            for j, g in enumerate(line):
                if g != 1:
                    continue
                for d in range(4):
                    ans = max(ans, self.dfs(i, j, d, 0))
        return ans
