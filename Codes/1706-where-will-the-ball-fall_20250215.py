'''
Author: LetMeFly
Date: 2025-02-15 11:20:53
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-15 11:24:22
Description: AC,67.31%,26.92%
'''
from typing import List

class Solution:
    def drop(self, j: int) -> None:
        y = j
        for x in range(len(self.grid)):
            nextY = self.grid[x][y] + y
            if nextY < 0 or nextY >= len(self.grid[0]) or self.grid[x][y] != self.grid[x][nextY]:
                return
            y = nextY
        self.ans[j] = y        

    def findBall(self, grid: List[List[int]]) -> List[int]:
        self.grid = grid
        self.ans = [-1] * len(grid[0])
        for j in range(len(grid[0])):
            self.drop(j)
        return self.ans