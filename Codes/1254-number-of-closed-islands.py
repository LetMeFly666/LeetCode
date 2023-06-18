'''
Author: LetMeFly
Date: 2023-06-18 13:10:41
LastEditors: LetMeFly
LastEditTime: 2023-06-18 13:52:12
'''
from typing import List


directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

class Solution:
    def mark(self, grid: List[List[int]], x, y) -> None:
        q = []
        grid[x][y] = 1
        q.append((x, y))
        while q:
            x, y = q.pop()
            for dx, dy in directions:
                tx = dx + x
                ty = dy + y
                if 0 <= tx < len(grid) and 0 <= ty < len(grid[0]) and grid[tx][ty] == 0:
                    grid[tx][ty] = 1
                    q.append((tx, ty))
        
    def closedIsland(self, grid: List[List[int]]) -> int:
        for i in range(len(grid)):
            if grid[i][0] == 0:
                self.mark(grid, i, 0)
            if grid[i][-1] == 0:
                self.mark(grid, i, len(grid[0]) - 1)
        for j in range(len(grid[0])):
            if grid[0][j] == 0:
                self.mark(grid, 0, j)
            if grid[-1][j] == 0:
                self.mark(grid, len(grid) - 1, j)
        
        ans = 0
        for i in range(1, len(grid) - 1):
            for j in range(1, len(grid[0]) - 1):
                if grid[i][j] == 0:
                    self.mark(grid, i, j)
                    ans += 1
        return ans