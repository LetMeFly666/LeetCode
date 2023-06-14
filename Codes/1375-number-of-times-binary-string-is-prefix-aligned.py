'''
Author: LetMeFly
Date: 2023-06-14 17:12:45
LastEditors: LetMeFly
LastEditTime: 2023-06-14 18:02:26
'''
from typing import List

class Solution:
    def numTimesAllBlue(self, flips: List[int]) -> int:
        M = 0
        ans = 0
        for i in range(len(flips)):
            M = max(M, flips[i])
            ans += (M == i + 1)
        return ans