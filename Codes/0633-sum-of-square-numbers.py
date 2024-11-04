'''
Author: LetMeFly
Date: 2024-11-04 19:45:43
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-04 19:46:18
'''
from math import sqrt

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for a in range(int(sqrt(c)) + 1):
            b = sqrt(c - a * a)
            if b == int(b):
                return True
        return False