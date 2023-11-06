'''
Author: LetMeFly
Date: 2023-11-06 20:10:45
LastEditors: LetMeFly
LastEditTime: 2023-11-06 20:14:31
'''
from typing import List
from collections import defaultdict

class Solution:
    def genMask(self, s: str) -> int:
        ans = 0
        for c in s:
            ans |= (1 << (ord(c) - ord('a')))
        return ans
    
    def maxProduct(self, words: List[str]) -> int:
        ma = defaultdict(int)
        ans = 0
        for s in words:
            mask, length = self.genMask(s), len(s)
            for key, val in ma.items():
                if not key & mask:
                    ans = max(ans, val * length)
            ma[mask] = max(ma[mask], length)
        return ans
