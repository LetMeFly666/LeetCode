'''
Author: LetMeFly
Date: 2023-09-13 08:49:07
LastEditors: LetMeFly
LastEditTime: 2023-09-13 10:00:00
'''
from typing import List

class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        indices = [0] * n ** 2
        for i in range(n):
            for j in range(n):
                indices[grid[i][j]] = [i, j]
        nowX, nowY = -2, -1
        for i in range(n * n):
            nextX, nextY = indices[i]
            if abs(nextX - nowX) * abs(nextY - nowY) != 2:
                return False
            nowX, nowY = indices[i]
        return True