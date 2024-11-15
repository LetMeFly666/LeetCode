'''
Author: LetMeFly
Date: 2024-11-15 09:40:23
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-15 09:43:08
'''
from typing import List

class Solution:
    def forLine(self, grid: List[List[int]]) -> int:
        ans = 0
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m // 2):
                ans += grid[i][j] != grid[i][m - j - 1]
        return ans

    def forCol(self, grid: List[List[int]]) -> int:
        ans = 0
        n, m = len(grid), len(grid[0])
        for j in range(m):
            for i in range(n // 2):
                ans += grid[i][j] != grid[n - i - 1][j]
        return ans

    def minFlips(self, grid: List[List[int]]) -> int:
        return min(self.forLine(grid), self.forCol(grid))