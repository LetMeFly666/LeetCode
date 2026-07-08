'''
Author: LetMeFly
Date: 2026-07-08 11:47:30
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-08 11:50:59
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = len(intervals)
        maxr = 0
        for _, r in intervals:
            if r <= maxr:
                ans -= 1
            else:
                maxr = r
        return ans
