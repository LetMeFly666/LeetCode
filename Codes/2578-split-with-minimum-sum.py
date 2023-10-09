'''
Author: LetMeFly
Date: 2023-10-09 09:10:33
LastEditors: LetMeFly
LastEditTime: 2023-10-09 09:12:51
'''
class Solution:
    def splitNum(self, num: int) -> int:
        s = sorted(str(num))
        n = ['', '']
        for i in range(len(s)):
            n[i % 2] += s[i]
        return int(n[0]) + int(n[1])