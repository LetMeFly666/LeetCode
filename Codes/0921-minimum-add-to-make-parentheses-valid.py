'''
Author: LetMeFly
Date: 2026-10-06 11:26:43
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-06 11:31:33
'''
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = diff = 0
        for c in s:
            if c == '(':
                diff += 1
            elif diff:
                diff -= 1
            else:
                ans += 1
        return ans + diff
