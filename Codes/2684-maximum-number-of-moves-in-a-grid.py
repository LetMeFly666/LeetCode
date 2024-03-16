'''
Author: LetMeFly
Date: 2024-03-16 09:47:15
LastEditors: LetMeFly
LastEditTime: 2024-03-16 09:48:33
'''
from typing import List

class Solution:  # AC,80.00%,92.59%
    def maxMoves(self, grid: List[List[int]]) -> int:
        can = set(i for i in range(len(grid)))
        ans = 0
        while can:
            ans += 1
            if ans == len(grid[0]):
                break
            nextCan = set()
            for row in can:
                for j in range(-1, 2):
                    if row + j >= 0 and row + j < len(grid) and grid[row + j][ans] > grid[row][ans - 1]:
                        nextCan.add(row + j)
            can = nextCan
        return ans - 1
