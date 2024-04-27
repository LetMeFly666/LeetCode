'''
Author: LetMeFly
Date: 2024-04-27 11:08:12
LastEditors: LetMeFly
LastEditTime: 2024-04-27 11:09:26
'''
from typing import List

class Solution:
    def findColumnWidth(self, grid: List[List[int]]) -> List[int]:
        ans = [1] * len(grid[0])
        for j in range(len(grid[0])):
            thisAns = 1
            for i in range(len(grid)):
                thisAns = max(thisAns, len(str(grid[i][j])))
            ans[j] = thisAns
        return ans