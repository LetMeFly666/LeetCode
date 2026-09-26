'''
Author: LetMeFly
Date: 2026-02-18 14:51:23
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-18 15:02:19
'''
class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        x = (n >> 1) ^ n
        return (x + 1) & x == 0