'''
Author: LetMeFly
Date: 2025-02-02 11:06:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-02 11:07:44
'''
from typing import List

class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        for a, b in ops:
            m = min(m, a)
            n = min(n, b)
        return m * n