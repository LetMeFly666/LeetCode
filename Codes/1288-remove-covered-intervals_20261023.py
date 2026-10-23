'''
Author: LetMeFly
Date: 2026-10-23 21:05:27
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-23 21:11:59
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans, maxr = len(intervals), -1
        for _, p in intervals:
            if p <= maxr:
                ans -= 1
            else:
                maxr = p
        return ans
