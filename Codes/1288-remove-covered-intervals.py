'''
Author: LetMeFly
Date: 2026-07-07 22:09:22
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-07 22:19:44
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = len(intervals)
        R = 0
        for l, r in intervals:
            ans -= r <= R
            R = max(R, r)
        return ans
