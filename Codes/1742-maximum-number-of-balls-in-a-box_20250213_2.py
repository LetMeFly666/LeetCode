'''
Author: LetMeFly
Date: 2025-02-13 16:25:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-13 16:25:13
'''
from collections import Counter

class Solution:
    def countBalls(self, l: int, r: int) -> int:
        return max(Counter(sum(ord(c) - 48 for c in str(i)) for i in range(l, r + 1)).values())