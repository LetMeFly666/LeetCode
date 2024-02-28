'''
Author: LetMeFly
Date: 2024-02-28 21:16:15
LastEditors: LetMeFly
LastEditTime: 2024-02-28 21:17:40
'''
from typing import List

class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        ans = 0
        for i in range(n // 2 - 1, -1, -1):
            ans += abs(cost[i * 2 + 1] - cost[i * 2 + 2])
            cost[i] += max(cost[i * 2 + 1], cost[i * 2 + 2])
        return ans
