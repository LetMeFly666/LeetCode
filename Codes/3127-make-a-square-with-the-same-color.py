'''
Author: LetMeFly
Date: 2024-08-31 17:27:57
LastEditors: LetMeFly
LastEditTime: 2024-08-31 17:32:41
'''
from typing import List

class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                if (grid[i][j] == 'W') + (grid[i - 1][j] == 'W') + (grid[i][j - 1] == 'W') + (grid[i - 1][j - 1] == 'W') != 2:
                    return True
        return False