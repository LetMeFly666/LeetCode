'''
Author: LetMeFly
Date: 2024-02-02 17:26:05
LastEditors: LetMeFly
LastEditTime: 2024-02-02 17:28:15
'''
from typing import List

class Solution:
    def stoneGameVI(self, a: List[int], b: List[int]) -> int:
        for i in range(len(a)):
            a[i] += b[i]
        a_b = -sum(b)
        for i in range(0, len(a), 2):
            a_b += a[i]
        return 1 if a_b > 0 else -1 if a_b else 0
