'''
Author: LetMeFly
Date: 2025-08-09 22:23:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-09 22:35:10
'''
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0