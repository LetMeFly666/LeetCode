'''
Author: LetMeFly
Date: 2025-02-21 13:05:56
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-21 13:11:13
'''
from functools import cache


class Solution:
    @cache
    def dfs(self, n: int, startIndex: int) -> int:
        if n * self.perLen >= len(self.floor) - startIndex:
            return 0
        ans = self.dfs(n, startIndex + 1) + (self.floor[startIndex] == '1')
        if n:
            ans = min(ans, self.dfs(n - 1, startIndex + self.perLen))
        return ans
    
    def minimumWhiteTiles(self, floor: str, numCarpets: int, carpetLen: int) -> int:
        self.floor = floor
        self.perLen = carpetLen
        return self.dfs(numCarpets, 0)
