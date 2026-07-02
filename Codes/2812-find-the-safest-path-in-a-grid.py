'''
Author: LetMeFly
Date: 2026-07-01 17:16:47
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-02 16:48:04
'''
from typing import List
from collections import deque

class Solution:
    def genDis(self, grid: List[List[int]]):
        n, m = len(grid), len(grid[0])
        dis = [[-1] * m for _ in range(n)]
        q = deque()
        
        self.dis = dis

    def dfs(self) -> int:
        pass

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        self.genDis(grid)
        return self.dfs()
