'''
Author: LetMeFly
Date: 2023-01-27 10:02:37
LastEditors: LetMeFly
LastEditTime: 2023-01-27 10:06:55
'''



class Solution:
    def greatestLetter(self, s: str) -> str:
        se = set(s)
        for i in range(25, -1, -1):
            if chr(ord('a') + i) in se and chr(ord('A') + i) in se:
                return chr(ord('A') + i)
        return ""


"""
方法二：
"""
from string import ascii_lowercase, ascii_uppercase

class Solution:
    def greatestLetter(self, s: str) -> str:
        se = set(s)
        for lower, upper in zip(reversed(ascii_lowercase), reversed(ascii_uppercase)):
            if lower in se and upper in se:
                return upper
        return ""