'''
Author: LetMeFly
Date: 2023-05-07 16:42:49
LastEditors: LetMeFly
LastEditTime: 2023-05-07 16:46:51
'''
from typing import List

class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        bin = [0] * 60
        ans = 0
        for t in time:
            ans += bin[(60 - t % 60) % 60]
            bin[t % 60] += 1
        return ans