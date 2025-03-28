'''
Author: LetMeFly
Date: 2025-03-28 13:29:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-28 13:31:10
'''
class Solution:
    def minimizedStringLength(self, s: str) -> int:
        mask = 0
        for c in s:
            mask |= 1 << (ord(c) - 97)
        return mask.bit_count()  # python3.10