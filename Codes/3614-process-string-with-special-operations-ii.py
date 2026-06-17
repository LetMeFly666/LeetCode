'''
Author: LetMeFly
Date: 2026-06-17 09:48:28
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-17 09:56:35
'''
class Solution:
    def processStr(self, s: str, k: int) -> str:
        l = 0
        for c in s:
            if c.islower():
                l += 1
            elif c == '*':
                l = max(l - 1, 0)
            elif c == '#':
                l *= 2
        if k >= l:
            return '.'
        
        for i in range(len(s) - 1, -1, -1):
            c = s[i]
            if c.islower():
                if k == l - 1:
                    return c
                l -= 1
            elif c == '*':
                l += 1
            elif c == '#':
                k = k if k < l // 2 else k - l // 2
                l //= 2
            else:
                k = l - 1 - k
        return '?'  # FAKE RETURN
