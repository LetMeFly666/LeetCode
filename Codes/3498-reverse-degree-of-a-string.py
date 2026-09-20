'''
Author: LetMeFly
Date: 2026-09-20 10:25:05
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-20 10:42:23
'''
class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum((i + 1) * (26 - ord(c) + ord('a')) for i, c in enumerate(s))
