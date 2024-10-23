'''
Author: LetMeFly
Date: 2024-10-23 22:52:40
LastEditors: LetMeFly
LastEditTime: 2024-10-23 22:54:19
'''
from typing import List

class Solution:
    def countCompleteDayPairs(self, hours: List[int]) -> int:
        bin = [0] * 24
        for t in hours:
            bin[t % 24] += 1
        ans = bin[0] * (bin[0] - 1) // 2 + bin[12] * (bin[12] - 1) // 2
        for i in range(1, 12):
            ans += bin[i] * bin[24 - i]
        return ans