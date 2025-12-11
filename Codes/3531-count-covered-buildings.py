'''
Author: LetMeFly
Date: 2025-12-11 13:14:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-11 13:27:34
'''
from typing import List

class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        n += 1
        xm = [n] * n
        xM = [0] * n
        ym = [n] * n
        yM = [0] * n
        for x, y in buildings:
            xm[x] = min(xm[x], y)
            xM[x] = max(xM[x], y)
            ym[y] = min(ym[y], x)
            yM[y] = max(yM[y], x)
        ans = 0
        for x, y in buildings:
            ans += xm[x] < y < xM[x] and ym[y] < x < yM[y]
        return ans