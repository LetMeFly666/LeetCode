'''
Author: LetMeFly
Date: 2025-03-16 11:06:25
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-16 11:09:05
'''
class Solution:
    def largestVariance(self, s: str) -> int:
        ans = 0
        for i in range(26):
            a = chr(i + ord('a'))
            for j in range(26):
                b = chr(j + ord('a'))
                mayNoB, hasB = 0, -100000
                for c in s:
                    if c == a:
                        mayNoB = max(mayNoB + 1, 1)
                        hasB += 1
                    elif c == b:
                        mayNoB = max(mayNoB - 1, -1)
                        hasB = mayNoB
                    ans = max(ans, hasB)
        return ans