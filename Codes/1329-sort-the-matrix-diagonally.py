'''
Author: LetMeFly
Date: 2024-04-29 12:44:48
LastEditors: LetMeFly
LastEditTime: 2024-04-29 12:47:50
'''
from typing import List

class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        startPoints = []
        for j in range(m):
            startPoints.append((0, j))
        for i in range(1, n):
            startPoints.append((i, 0))
        for thisPoint in startPoints:
            i, j = thisPoint
            vals = []
            while i < n and j < m:
                vals.append(mat[i][j])
                i += 1
                j += 1
            vals.sort()
            index = 0
            i, j = thisPoint
            while i < n and j < m:
                mat[i][j] = vals[index]
                i += 1
                j += 1
                index += 1
        return mat
