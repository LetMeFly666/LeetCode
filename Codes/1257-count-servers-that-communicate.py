'''
Author: LetMeFly
Date: 2023-08-24 09:05:04
LastEditors: LetMeFly
LastEditTime: 2023-08-24 09:15:27
'''
from typing import List

class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        col, row = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                col[i] += grid[i][j]
                row[j] += grid[i][j]
        ans = 0
        for i in range(n):
            for j in range(m):
                ans += grid[i][j] * (col[i] > 1 or row[j] > 1)
        return ans