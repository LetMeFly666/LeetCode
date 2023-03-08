'''
Author: LetMeFly
Date: 2023-03-08 17:48:05
LastEditors: LetMeFly
LastEditTime: 2023-03-08 17:49:55
'''
from typing import List


class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    continue
                elif i == 0 and j!= 0:
                    grid[i][j] += grid[i][j - 1]
                elif i != 0 and j == 0:
                    grid[i][j] += grid[i - 1][j]
                else:
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1])
        return grid[n - 1][m - 1]