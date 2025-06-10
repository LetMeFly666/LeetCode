'''
Author: LetMeFly
Date: 2025-06-10 23:07:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-10 23:18:45
'''
from collections import Counter

class Solution:
    def maxDifference(self, s: str) -> int:
        cnt = Counter(s)
        return max(v for v in cnt.values() if v % 2) - min(v for v in cnt.values() if v % 2 == 0)