'''
Author: LetMeFly
Date: 2026-09-24 12:11:42
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-24 12:23:37
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = len(intervals)
        maxr = -1
        for _, p in intervals:
            if maxr >= p:
                ans -= 1
            else:
                maxr = p
        return ans
