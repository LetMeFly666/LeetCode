'''
Author: LetMeFly
Date: 2023-12-13 09:39:29
LastEditors: LetMeFly
LastEditTime: 2023-12-13 09:43:23
'''
class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        li = list(s)
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - i - 1]:
                li[i] = li[len(s) - i - 1] = min(s[i], s[len(s) - i - 1])
        return ''.join(li)