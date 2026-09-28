'''
Author: LetMeFly
Date: 2026-09-28 08:10:10
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-28 08:19:18
'''
class Solution:
    def maxDepth(self, s: str) -> int:
        layer = ans = 0
        for i, c in enumerate(s):
            if c == '(':
                layer += 1
                ans = max(ans, layer)
            elif c == ')':
                layer -= 1
        return ans
