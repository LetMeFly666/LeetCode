'''
Author: LetMeFly
Date: 2024-07-05 21:42:01
LastEditors: LetMeFly
LastEditTime: 2024-07-05 21:43:21
'''
from typing import List

class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        for j in range(0, len(matrix[0])):
            M = matrix[0][j]
            for i in range(1, len(matrix)):
                M = max(M, matrix[i][j])
            for i in range(0, len(matrix)):
                if matrix[i][j] == -1:
                    matrix[i][j] = M
        return matrix