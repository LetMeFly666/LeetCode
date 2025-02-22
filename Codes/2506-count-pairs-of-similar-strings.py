'''
Author: LetMeFly
Date: 2025-02-22 11:16:23
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-22 11:19:02
'''
from typing import List
from collections import defaultdict

class Solution:
    def code(self, word: str) -> int:
        ans = 0
        for c in word:
            ans |= 1 << (ord(c) - 97)
        return ans
    
    def similarPairs(self, words: List[str]) -> int:
        ans = 0
        ma = defaultdict(int)
        for s in words:
            c = self.code(s)
            ans += ma[c]
            ma[c] += 1
        return ans