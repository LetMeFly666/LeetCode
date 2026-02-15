'''
Author: LetMeFly
Date: 2026-02-15 12:27:51
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-15 12:44:46
'''
# THIS CANNOT BE ACCPETED
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return format((int(a) + int(b)), 'b')