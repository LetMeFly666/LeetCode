'''
Author: LetMeFly
Date: 2026-10-05 16:38:39
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-05 16:45:23
'''
class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        ans = layer = 0
        for i, c in enumerate(s):
            if c == '(':
                layer += 1
            else:
                layer -= 1
                if s[i - 1] == '(':
                    ans += 1 << layer
        return ans
