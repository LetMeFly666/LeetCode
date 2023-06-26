'''
Author: LetMeFly
Date: 2023-06-26 09:34:16
LastEditors: LetMeFly
LastEditTime: 2023-06-26 09:41:58
'''
from math import sqrt

class Solution:
    def pivotInteger(self, n: int) -> int:
        ans = int(sqrt((n * n + n) / 2))
        return ans if ans * ans == (n * n + n) / 2 else -1