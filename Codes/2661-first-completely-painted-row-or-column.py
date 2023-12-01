'''
Author: LetMeFly
Date: 2023-12-01 10:22:10
LastEditors: LetMeFly
LastEditTime: 2023-12-01 10:25:53
'''
from typing import List

class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        a = [[] for _ in range(n * m)]
        for i in range(n):
            for j in range(m):
                a[mat[i][j] - 1] = [i, j]
        rowCnt, colCnt = [0] * n, [0] * m
        for i in range(len(arr)):
            t = arr[i] - 1
            rowCnt[a[t][0]] += 1
            colCnt[a[t][1]] += 1
            if rowCnt[a[t][0]] == m or colCnt[a[t][1]] == n:
                return i
        return -1  # Fake Return
