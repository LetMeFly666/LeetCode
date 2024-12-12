'''
Author: LetMeFly
Date: 2024-12-12 14:37:52
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-12 14:41:16
'''
from typing import List

class Solution:
    def maxSpending(self, values: List[List[int]]) -> int:
        loc = [len(values[0]) - 1] * len(values)
        ans, cnt, th = 0, len(values) * len(values[0]), 1
        while th <= cnt:
            m, mLoc = 10000000, 0
            for i in range(len(values)):
                if loc[i] >= 0 and values[i][loc[i]] < m:
                    m, mLoc = values[i][loc[i]], i
            ans += th * values[mLoc][loc[mLoc]]
            th += 1
            loc[mLoc] -= 1
        return ans