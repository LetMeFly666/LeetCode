'''
Author: LetMeFly
Date: 2025-03-31 13:31:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-31 13:31:35
'''
class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return s.count(letter) * 100 // len(s)