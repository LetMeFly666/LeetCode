'''
Author: LetMeFly
Date: 2024-12-25 20:27:10
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-25 20:34:17
'''
from typing import List
from functools import cache

class Solution:
    @cache
    def dfs(self, ia: int, ib: int, ja: int, jb: int) -> int:
        if ib - ia == 1 and jb - ja == 1:
            return 0
        ans = 1000000000
        for ic in range(ia + 1, ib):
            ans = min(ans, self.h[ic - 1] + self.dfs(ia, ic, ja, jb) + self.dfs(ic, ib, ja, jb))
        for jc in range(ja + 1, jb):
            ans = min(ans, self.v[jc - 1] + self.dfs(ia, ib, ja, jc) + self.dfs(ia, ib, jc, jb))
        return ans

    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        self.h, self.v = horizontalCut, verticalCut
        return self.dfs(0, m, 0, n)