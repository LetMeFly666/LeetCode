'''
Author: LetMeFly
Date: 2025-08-15 18:29:00
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-15 18:52:04
'''
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        return n > 0 and n & (n - 1) == 0 and n % 3 == 1