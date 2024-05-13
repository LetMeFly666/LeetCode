'''
Author: LetMeFly
Date: 2024-05-13 14:13:14
LastEditors: LetMeFly
LastEditTime: 2024-05-13 14:25:30
'''
from typing import List


DIRECTIONS = [[0, -1], [0, 1], [-1, 0], [1, 0]]

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ans = 0
        cntNormal = 0
        q = []
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    cntNormal += 1
                elif grid[i][j] == 2:
                    q.append((i, j))
                    grid[i][j] = 0
        while q:
            hasNew = False
            newQ = []
            for x, y in q:
                for dx, dy in DIRECTIONS:
                    newX, newY = x + dx, y + dy
                    if newX >= 0 and newX < len(grid) and newY >= 0 and newY < len(grid[0]) and grid[newX][newY] == 1:
                        newQ.append((newX, newY))
                        grid[newX][newY] = 0
                        cntNormal -= 1
                        hasNew = True
            q = newQ
            ans += hasNew
        return -1 if cntNormal else ans