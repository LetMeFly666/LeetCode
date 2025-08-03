'''
Author: LetMeFly
Date: 2025-08-03 22:53:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-04 00:07:41
'''
from typing import List
from collections import defaultdict

class Solution:
    def minCost(self, basket1: List[int], basket2: List[int]) -> int:
        m = min(min(basket1), min(basket2))
        diffTimes = defaultdict(int)
        for t in basket1:
            diffTimes[t] += 1
        for t in basket2:
            diffTimes[t] -= 1
        change = []
        for val, times in diffTimes.items():
            if not times:
                continue
            if times % 2:
                return -1
            for _ in range(abs(times) // 2):
                change.append(val)
        change.sort()
        return sum(min(m * 2, t) for t in change[:len(change) // 2])