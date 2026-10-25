'''
Author: LetMeFly
Date: 2026-10-25 09:03:15
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-25 09:24:54
'''
from typing import List

dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]

class Solution:
    def isCenter(self, i: int, j: int) -> bool:
        return 0 < i < self.n - 1 and 0 < j < self.m - 1
    
    def inGrid(self, i: int, j: int) -> bool:
        return 0 <= i < self.n and 0 <= j < self.m
    
    def closedIsland(self, grid: List[List[int]]) -> int:
        self.n = len(grid)
        self.m = len(grid[0])
        ans = 0
        for i, line in enumerate(grid):
            for j, v in enumerate(line):
                if v:
                    continue
                grid[i][j] = 1
                ok = self.isCenter(i, j)
                q = [(i, j)]
                while q:
                    x, y = q.pop()
                    for dx, dy in dirs:
                        nx, ny = x + dx, y + dy
                        if not self.inGrid(nx, ny) or grid[nx][ny]:
                            continue
                        grid[nx][ny] = 1
                        ok &= self.isCenter(nx, ny)
                        q.append((nx, ny))
                ans += ok
        return ans
