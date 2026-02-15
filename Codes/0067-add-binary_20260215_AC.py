'''
Author: LetMeFly
Date: 2026-02-15 12:27:51
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-15 12:45:41
'''
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return format((int(a, 2) + int(b, 2)), 'b')