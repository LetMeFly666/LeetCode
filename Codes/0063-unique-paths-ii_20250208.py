'''
Author: LetMeFly
Date: 2025-02-08 09:55:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-08 09:58:42
'''
from typing import List

class Solution:
    def uniquePathsWithObstacles(self, a: List[List[int]]) -> int:
        a[0][0] = 0 if a[0][0] else 1
        for i in range(len(a)):
            for j in range(len(a[0])):
                if a[i][j] != 0 and (i or j):
                    a[i][j] = 0
                    continue
                if i > 0:
                    a[i][j] += a[i - 1][j]
                if j > 0:
                    a[i][j] += a[i][j - 1]
        return a[-1][-1]