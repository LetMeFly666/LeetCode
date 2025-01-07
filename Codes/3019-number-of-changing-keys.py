'''
Author: LetMeFly
Date: 2025-01-07 13:09:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-07 13:09:43
'''
class Solution:
    def countKeyChanges(self, s: str) -> int:
        return sum(s[i].lower() != s[i - 1].lower() for i in range(1, len(s)))