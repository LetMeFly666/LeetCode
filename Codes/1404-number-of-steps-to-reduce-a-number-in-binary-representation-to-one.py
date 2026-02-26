'''
Author: LetMeFly
Date: 2026-02-26 23:55:52
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-26 23:56:54
'''
class Solution:
    def numSteps(self, s: str) -> int:
        a = int(s)
        ans = 0
        while a:
            if a % 2:
                a += 1
            else:
                a //= 2
            ans += 1
        return ans
