'''
Author: LetMeFly
Date: 2025-08-26 21:25:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-26 21:34:38
'''
from typing import List
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        ans = M = 0
        for a, b in dimensions:
            l2 = a * a + b * b
            if l2 > M:
                M = l2
                ans = a * b
            elif l2 == M:
                ans = max(ans, a * b)
        return ans