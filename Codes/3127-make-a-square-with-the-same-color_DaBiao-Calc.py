'''
Author: LetMeFly
Date: 2024-08-31 17:42:56
LastEditors: LetMeFly
LastEditTime: 2024-08-31 17:51:26
'''
from typing import List

class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                if (grid[i][j] == 'W') + (grid[i - 1][j] == 'W') + (grid[i][j - 1] == 'W') + (grid[i - 1][j - 1] == 'W') != 2:
                    return True
        return False

cannot = []
sol = Solution()
for code in range(1 << 9):
    grid = [['W' if (code & (1 << (i * 3 + j))) else 'B' for j in range(3)] for i in range(3)]
    if grid == [['B', 'W', 'B'], ['W', 'B', 'W'], ['B', 'W', 'B']]:
        print(code)
    # print(grid)
    if not sol.canMakeSquare(grid):
        cannot.append(code)
print(cannot)

# [56, 113, 146, 149, 170, 173, 227, 284, 338, 341, 362, 365, 398, 455]