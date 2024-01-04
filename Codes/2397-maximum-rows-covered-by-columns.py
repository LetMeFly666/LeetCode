'''
Author: LetMeFly
Date: 2024-01-04 21:14:03
LastEditors: LetMeFly
LastEditTime: 2024-01-04 21:17:28
'''
from typing import List

class Solution:
    def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
        ans = 0
        m, n = len(matrix), len(matrix[0])
        for state in range(1 << n):
            if bin(state).count('1') != numSelect:
                continue
            thisAns = 0
            for i in range(m):
                can = True
                for j in range(n):
                    if matrix[i][j] and not state & (1 << j):
                        can = False
                        break
                thisAns += can
            ans = max(ans, thisAns)
        return ans