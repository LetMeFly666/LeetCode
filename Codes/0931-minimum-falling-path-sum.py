'''
Author: LetMeFly
Date: 2023-07-13 08:11:20
LastEditors: LetMeFly
LastEditTime: 2023-07-13 08:19:14
'''
from typing import List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        for i in range(1, n):
            for j in range(n):
                m = 1e8
                for k in range(-1, 2):
                    if 0 <= j + k < n:
                        m = min(m, matrix[i - 1][j + k])
                matrix[i][j] += m
        return min(matrix[-1])