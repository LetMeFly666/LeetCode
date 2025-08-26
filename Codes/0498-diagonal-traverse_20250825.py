'''
Author: LetMeFly
Date: 2025-08-25 18:56:28
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-25 23:54:37
'''
from typing import List

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans: List[int] = []
        n, m = len(mat), len(mat[0])
        for k in range(m + n - 1):
            if k % 2:
                j = min(k, m - 1)
                i = k - j
                while i < n and j >= 0:
                    ans.append(mat[i][j])
                    i += 1
                    j -= 1
            else:
                i = min(k, n - 1)
                j = k - i
                while i >= 0 and j < m:
                    ans.append(mat[i][j])
                    i -= 1
                    j += 1
        return ans