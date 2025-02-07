'''
Author: LetMeFly
Date: 2025-02-07 20:38:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-07 20:49:54
'''
from typing import List


class Solution:
    def __init__(self):
        self.directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    
    def generateMatrix(self, n: int) -> List[List[int]]:
        ans = [[0] * n for _ in range(n)]
        d = x = y = 0
        for i in range(n * n):
            ans[x][y] = i + 1
            nx, ny = x + self.directions[d][0], y + self.directions[d][1]
            if nx == n or nx < 0 or ny == n or ny < 0 or ans[nx][ny]:
                d = (d + 1) % 4
                nx, ny = x + self.directions[d][0], y + self.directions[d][1]
            x, y = nx, ny
        return ans