'''
Author: LetMeFly
Date: 2025-04-12 22:20:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-12 22:28:31
'''
from functools import cache

class Solution:
    @cache
    def dfs(self, n: int, limitLow: bool, limitHigh: bool) -> int:
        if n == self.n:
            return 1
        low = self.start[n] if limitLow else 0
        high = self.finish[n] if limitHigh else 0
        ans = 0
        if n < self.free:  # 什么都可以
            for d in range(low, high + 1):
                ans += self.dfs(n + 1, limitLow and d == low, limitHigh and d == high)
        else:
            x = self.s[n - self.free]
            if low <= x <= high:
                ans = self.dfs(n + 1, limitLow and x == low, limitHigh and x == high)
        return ans
        
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        self.start = list(map(int, str(start)))
        self.n = len(self.start)
        self.finish = list(map(int, str(finish).zfill(self.n)))
        self.limit = limit
        self.free = self.n - len(s)
        self.s = list(map(int, s))
        return self.dfs(0, True, True)