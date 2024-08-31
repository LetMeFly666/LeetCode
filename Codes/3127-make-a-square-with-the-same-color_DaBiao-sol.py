'''
Author: LetMeFly
Date: 2024-08-31 17:48:25
LastEditors: LetMeFly
LastEditTime: 2024-08-31 17:52:27
'''
from typing import List

cannot = [56, 113, 146, 149, 170, 173, 227, 284, 338, 341, 362, 365, 398, 455]

class Solution:
    def grid2code(self, grid: List[List[str]]) -> int:
        ans = 0
        for i in range(3):
            for j in range(3):
                if grid[i][j] == 'W':
                    ans |= (1 << (i * 3 + j))
        return ans

    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        return self.grid2code(grid) not in cannot