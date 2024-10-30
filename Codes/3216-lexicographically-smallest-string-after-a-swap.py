'''
Author: LetMeFly
Date: 2024-10-30 12:28:40
LastEditors: LetMeFly
LastEditTime: 2024-10-30 12:31:52
'''

"""
# FirstTry: RE - TypeError: 'str' object does not support item assignment
class Solution:
    def getSmallestString(self, s: str) -> str:
        for i in range(1, len(s)):
            if ord(s[i - 1]) > ord(s[i]) and ord(s[i - 1]) % 2 == ord(s[i]) % 2:
                s[i - 1], s[i] = s[i], s[i - 1]
                return s
        return s
"""

class Solution:
    def getSmallestString(self, s: str) -> str:
        temp = list(s)
        for i in range(1, len(s)):
            if ord(temp[i - 1]) > ord(temp[i]) and ord(temp[i - 1]) % 2 == ord(temp[i]) % 2:
                temp[i - 1], temp[i] = temp[i], temp[i - 1]
                break
        return ''.join(temp)
