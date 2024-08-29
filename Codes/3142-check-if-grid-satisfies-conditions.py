'''
Author: LetMeFly
Date: 2024-08-29 23:19:22
LastEditors: LetMeFly
LastEditTime: 2024-08-29 23:19:38
'''
from typing import List

class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        for j in range(len(grid[0])):
            if j and grid[0][j] == grid[0][j - 1]:
                return False
            for i in range(1, len(grid)):
                if grid[i][j] != grid[i - 1][j]:
                    return False
        return True