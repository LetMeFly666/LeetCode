'''
Author: LetMeFly
Date: 2024-12-20 20:53:20
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-20 20:56:17
'''
from collections import Counter

class Solution:
    def minAnagramLength(self, s: str) -> int:
        for ans in range(1, len(s)):
            if len(s) % ans:
                continue
            should = Counter(s[:ans])
            ok = True
            for i in range(ans, len(s), ans):
                if should != Counter(s[i:i + ans]):
                    ok = False
                    break
            if ok:
                return ans
        return len(s)