'''
Author: LetMeFly
Date: 2023-08-11 08:00:08
LastEditors: LetMeFly
LastEditTime: 2023-08-11 08:00:09
'''
from typing import List

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        ans = 0
        for i in range(n):
            ans += mat[i][i] + mat[i][n - i - 1]
        if n % 2:
            ans -= mat[n // 2][n // 2]
        return ans