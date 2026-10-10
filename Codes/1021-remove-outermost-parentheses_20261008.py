'''
Author: LetMeFly
Date: 2026-10-08 08:52:58
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-08 10:07:08
'''
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        ans = []
        layer = 0
        for c in s:
            if c == '(':
                if layer:
                    ans.append(c)
                layer += 1
            else:
                layer -= 1
                if layer:
                    ans.append(c)
        return ''.join(ans)
