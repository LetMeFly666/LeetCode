'''
Author: LetMeFly
Date: 2025-06-09 10:09:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-09 10:18:26
'''
from typing import List

class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        ans = [0] * n
        now = 1
        for i in range(n):
            ans[i] = now
            if now * 10 <= n:
                now *= 10
            else:
                while now % 10 == 9:
                    now //= 10
                if now == n:
                    now //= 10
                now += 1
        return ans