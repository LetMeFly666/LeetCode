'''
Author: LetMeFly
Date: 2025-03-15 10:28:26
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-15 10:28:50
'''
class Solution:
    def scoreOfString(self, s: str) -> int:
        return sum(abs(ord(s[i]) - ord(s[i - 1])) for i in range(1, len(s)))