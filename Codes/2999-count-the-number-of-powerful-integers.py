'''
Author: LetMeFly
Date: 2025-04-10 22:12:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-10 22:34:11
'''
from functools import cache

class Solution:
    @cache
    def dfs(self, i: int, limitLow: bool, limitHigh: bool) -> int:
        if i == self.n:
            return 1
        low = self.low[i] if limitLow else 0
        high = self.high[i] if limitHigh else 9
        ans = 0
        if i < self.free:
            for d in range(low, min(high, self.limit) + 1):
                ans += self.dfs(i + 1, limitLow and d == low, limitHigh and d == high)
        else:
            x = int(self.s[i - self.free])
            if low <= x <= high:
                ans = self.dfs(i + 1, limitLow and x == low, limitHigh and x == high)
        return ans

    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        self.high = list(map(int, str(finish)))
        self.n = len(self.high)
        self.low = list(map(int, str(start).zfill(self.n)))
        self.free = self.n - len(s)
        self.limit = limit
        self.s = s
        return self.dfs(0, True, True)

# if __name__ == '__main__':
#     sol = Solution()
#     ans = sol.numberOfPowerfulInt(2, 100, 3, "3")  # 1
#     print(ans)