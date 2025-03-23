'''
Author: LetMeFly
Date: 2025-03-23 10:49:44
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-23 10:51:19
'''
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        l = r = 0
        for i in range(len(s)):
            if locked[i] == '0':
                l -= 1
                r += 1
                if l == -1:
                    l = 1
            else:
                if s[i] == '(':
                    l += 1
                    r += 1
                else:
                    l -= 1
                    r -= 1
                    if r < 0:
                        return False
                    if l < 0:
                        l = 1
        return not l