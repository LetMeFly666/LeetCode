'''
Author: LetMeFly
Date: 2025-03-27 22:02:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-27 22:05:06
'''
class Solution:
    def minimumCost(self, s: str) -> int:
        ans = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                ans += min(i, len(s) - i)
        return ans