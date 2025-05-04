'''
Author: LetMeFly
Date: 2025-05-04 14:26:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-04 16:10:15
'''
from typing import List

class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        times = [0] * 81
        ans = 0
        for a, b in dominoes:
            v = (a - 1) * 9 + (b - 1) if a < b else (b - 1) * 9 + (a - 1)
            ans += times[v]
            times[v] += 1
        return ans