'''
Author: LetMeFly
Date: 2025-03-10 12:43:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-10 12:44:22
'''
class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        ans = 0
        for i in range(len(s) - k + 1):
            thisNum = 0
            for j in range(k):
                thisNum = thisNum * 10 + ord(s[i + j]) - 48
            ans += thisNum and num % thisNum == 0
        return ans