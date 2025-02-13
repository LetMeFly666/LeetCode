'''
Author: LetMeFly
Date: 2025-02-13 16:22:09
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-13 16:23:53
'''
from collections import Counter

class Solution:
    def get(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans

    def countBalls(self, l: int, r: int) -> int:
        return max(Counter(self.get(i) for i in range(l, r + 1)).values())