'''
Author: LetMeFly
Date: 2025-04-12 09:44:25
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-12 10:52:36
Description: 中间终中断了下
'''
from collections import Counter

class Solution:
    def isOk(self, s: str) -> bool:
        return int(s) % self.k == 0
    
    def ifVisited(self, s: str) -> bool:
        s = ''.join(sorted(s))
        if s in self.visited:
            return True
        self.visited.add(s)
        return False
    
    def calc(self, s: str) -> int:
        times = Counter(s)
        ans = (len(s) - times['0']) * self.factor[len(s) - 1]
        for _, val in times.items():
            ans //= self.factor[val]
        return ans

    def countGoodIntegers(self, n: int, k: int) -> int:
        self.k = k
        self.factor = [1] * (n + 1)
        for i in range(1, n + 1):
            self.factor[i] = self.factor[i - 1] * i
        self.visited = set()
        base = pow(10, (n - 1) // 2)
        ans = 0
        for i in range(base, base * 10):
            prefix = str(i)
            s = prefix + prefix[::-1][n % 2:]
            if self.isOk(s) and not self.ifVisited(s):
                ans += self.calc(s)
        return ans
