'''
Author: LetMeFly
Date: 2026-08-06 15:20:51
LastEditors: LetMeFly.xyz
LastEditTime: 2026-08-06 15:24:33
'''
class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            mul = 1
            for i in str(n):
                mul *= ord(i) - ord('0')
            if mul % t == 0:
                return n
            n += 1
