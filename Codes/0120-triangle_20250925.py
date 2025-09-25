'''
Author: LetMeFly
Date: 2025-09-25 23:12:43
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-25 23:24:36
'''
from typing import List

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # for line in triangle[-2:-1:-1]:
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(i + 1):
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j - 1])
        return triangle[0][0]