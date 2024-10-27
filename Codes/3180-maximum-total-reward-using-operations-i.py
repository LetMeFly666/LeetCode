'''
Author: LetMeFly
Date: 2024-10-26 09:43:01
LastEditors: LetMeFly
LastEditTime: 2024-10-26 09:44:10
'''
from typing import List

class Solution:
    def maxTotalReward(self, rewardValues: List[int]) -> int:
        rewardValues.sort()
        dp = [False] * (rewardValues[-1] * 2)
        dp[0] = True
        for x in rewardValues:
            