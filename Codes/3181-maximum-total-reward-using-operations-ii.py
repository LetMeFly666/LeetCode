'''
Author: LetMeFly
Date: 2024-10-30 10:26:34
LastEditors: LetMeFly
LastEditTime: 2024-10-30 10:33:24
'''
from typing import List

class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        dp = 1
        for x in rewardValues:
            dp |= (dp & ((1 << x) - 1)) << x
        return dp.bit_length() - 1