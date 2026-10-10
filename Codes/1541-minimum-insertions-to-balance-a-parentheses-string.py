'''
Author: LetMeFly
Date: 2026-10-10 09:34:46
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-10 09:39:02
'''
class Solution:
    def minInsertions(self, s: str) -> int:
        ans = diff = i = 0
        n = len(s)
        while i < n:
            if s[i] == '(':
                diff += 1
            else:
                if diff:
                    diff -= 1
                else:
                    ans += 1
                if i + 1 < n and s[i + 1] == ')':
                    i += 1
                else:
                    ans += 1
            i += 1
        return ans + diff * 2
