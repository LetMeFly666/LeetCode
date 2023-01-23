'''
Author: LetMeFly
Date: 2023-01-23 10:01:38
LastEditors: LetMeFly
LastEditTime: 2023-01-23 10:03:55
'''
from typing import List


class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        ans = 0
        lastUpper = 0
        for v in brackets:
            ans += (min(v[0], income) - lastUpper) * v[1] / 100
            lastUpper = v[0]
            if v[0] >= income:
                break
        return ans