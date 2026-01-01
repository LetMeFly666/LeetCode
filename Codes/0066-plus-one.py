'''
Author: LetMeFly
Date: 2026-01-01 15:40:30
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-01 15:54:44
'''
from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        cnt = 1
        for i in range(len(digits) - 1, -1, -1):
            digits[i] += cnt
            cnt = digits[i] // 10
            digits[i] %= 10
        if cnt:
            digits = [1] + digits
        return digits