'''
Author: LetMeFly
Date: 2024-08-22 23:11:41
LastEditors: LetMeFly
LastEditTime: 2024-08-22 23:12:58
'''
class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        ix = 0
        for in_ in range(27):
            while (x >> ix) & 1:
                ix += 1
            x |= (((n >> in_) & 1) << ix)
            ix += 1
        return x