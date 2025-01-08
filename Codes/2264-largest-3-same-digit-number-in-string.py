'''
Author: LetMeFly
Date: 2025-01-08 15:34:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-08 15:36:15
'''
class Solution:
    def largestGoodInteger(self, s: str) -> str:
        M = '/'
        for i in range(2, len(s)):
            if s[i] == s[i - 1] == s[i - 2]:
                M = max(M, s[i])
        return '' if M == '/' else M * 3