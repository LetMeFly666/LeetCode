'''
Author: LetMeFly
Date: 2026-01-05 13:31:38
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-05 13:41:10
'''
from typing import List

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        mini = 1000000
        cntNeg = 0
        ans = 0
        for row in matrix:
            for t in row:
                ans += abs(t)
                if t < 0:
                    cntNeg += 1
                mini = min(mini, abs(t))
        if cntNeg % 2:
            ans -= 2 * mini
        return ans