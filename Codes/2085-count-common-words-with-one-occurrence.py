'''
Author: LetMeFly
Date: 2024-01-12 19:07:38
LastEditors: LetMeFly
LastEditTime: 2024-01-12 19:08:56
'''
from typing import List
from collections import defaultdict

class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        m1, m2 = defaultdict(int), defaultdict(int)
        for s in words1:
            m1[s] += 1
        for s in words2:
            m2[s] += 1
        ans = 0
        for s, cnt in m1.items():
            if cnt == 1 and m2[s] == 1:
                ans += 1
        return ans
