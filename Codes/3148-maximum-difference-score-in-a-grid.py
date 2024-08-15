'''
Author: LetMeFly
Date: 2024-08-15 23:57:36
LastEditors: LetMeFly
LastEditTime: 2024-08-15 23:59:16
'''
from typing import List

class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        ans = grid[0][1] - grid[0][0]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                original = grid[i][j]
                if i > 0:
                    grid[i][j] = min(grid[i][j], grid[i - 1][j])
                    ans = max(ans, original - grid[i - 1][j])
                if j > 0:
                    grid[i][j] = min(grid[i][j], grid[i][j - 1])
                    ans = max(ans, original - grid[i][j - 1])
        return ans