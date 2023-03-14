'''
Author: LetMeFly
Date: 2023-03-14 13:46:43
LastEditors: LetMeFly
LastEditTime: 2023-03-14 13:53:42
'''
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(i[::-1] for i in s.split())