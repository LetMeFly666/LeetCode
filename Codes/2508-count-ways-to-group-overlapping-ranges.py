'''
Author: LetMeFly
Date: 2024-03-27 13:12:26
LastEditors: LetMeFly
LastEditTime: 2024-03-27 13:14:29
'''
from typing import List


MOD = int(1e9) + 7

class Solution:
    def countWays(self, ranges: List[List[int]]) -> int:
        ranges.sort()
        lastTo = -1
        ans = 1
        for from_, to in ranges:
            if from_ > lastTo:
                ans = ans * 2 % MOD
            lastTo = max(lastTo, to)
        return ans
