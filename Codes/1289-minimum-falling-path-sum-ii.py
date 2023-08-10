'''
Author: LetMeFly
Date: 2023-08-10 07:57:40
LastEditors: LetMeFly
LastEditTime: 2023-08-10 08:25:51
'''
from typing import List

class Solution:
    def findMin2(self, v: List[int]) -> List[int]:
        ans = [0, 0]
        m, loc = v[0], 0
        for i in range(len(v)):
            if v[i] < m:
                m, loc = v[i], i
        ans[0] = loc
        loc = 0 if ans[0] else 1
        m = v[loc]
        for i in range(len(v)):
            if v[i] < m and i != ans[0]:
                m, loc = v[i], i
        ans[1] = loc
        return ans
    
    def minFallingPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid)
        for i in range(1, n):
            last2min = self.findMin2(grid[i - 1])
            for j in range(n):
                grid[i][j] += grid[i - 1][last2min[0]] if j != last2min[0] else grid[i - 1][last2min[1]]
        return min(grid[-1])
