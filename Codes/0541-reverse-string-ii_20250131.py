'''
Author: LetMeFly
Date: 2025-01-31 12:02:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-31 12:08:02
'''
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        for l in range(0, len(s), k * 2):
            s[l:l + k] = s[l:l + k][::-1]
        return ''.join(s)