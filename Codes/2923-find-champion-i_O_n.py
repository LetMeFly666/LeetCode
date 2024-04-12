'''
Author: LetMeFly
Date: 2024-04-12 13:51:26
LastEditors: LetMeFly
LastEditTime: 2024-04-12 13:51:35
'''
from typing import List

class Solution:
    def findChampion(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            if grid[i][ans]:
                ans = i
        return ans