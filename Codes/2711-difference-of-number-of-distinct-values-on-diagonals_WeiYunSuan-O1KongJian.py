'''
Author: LetMeFly
Date: 2025-03-25 21:18:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-25 21:23:09
'''
from typing import List

class Solution:
    def differenceOfDistinctValues(self, grid: List[List[int]]) -> List[List[int]]:
        n, m = len(grid), len(grid[0])
        ans = [[0] * m for _ in range(n)]
        for k in range(m + n - 1):
            i = 0 if k < m else k - m + 1
            j = k if k < m else 0
            se = d = 0
            while i + d < n and j + d < m:
                ans[i + d][j + d] = se.bit_count()  # python10才有
                se |= 1 << grid[i + d][j + d]
                d += 1
            se = 0
            d -= 1
            while d >= 0:
                ans[i + d][j + d] = abs(ans[i + d][j + d] - se.bit_count())
                se |= 1 << grid[i + d][j + d]
                d -= 1
        return ans