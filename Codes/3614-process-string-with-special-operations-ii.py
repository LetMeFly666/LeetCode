'''
Author: LetMeFly
Date: 2026-06-17 09:48:28
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-17 09:56:35
'''
class Solution:
    def processStr(self, s: str, k: int) -> str:
        len = 0
        for c in s:
            if c.islower():
                len += 1
            elif c == '*':
                len = max(len - 1, 0)
            elif c == '#':
                len *= 2
        if k >= len:
            return '.'
        
        for i in range(len(s) - 1, -1, -1):
            c = s[i]
            if c.islower():
                if k == len - 1:
                    return c
                len -= 1
            elif c == '*':
                len += 1
            elif c == '#':
                k = k if k < len // 2 else k - len // 2
                len //= 2
            else:
                k = len - 1 - k
        return '?'  # FAKE RETURN
