'''
Author: LetMeFly
Date: 2025-02-19 17:47:16
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-19 17:49:04
'''
from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        ans = 0
        m, M = 100000, -100000
        for a in arrays:
            ans = max(ans, M - a[0], a[-1] - m)
            m, M = min(m, a[0]), max(M, a[-1])
        return ans