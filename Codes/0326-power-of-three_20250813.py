'''
Author: LetMeFly
Date: 2025-08-13 13:17:09
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-13 13:24:54
'''
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and not 1162261467 % n