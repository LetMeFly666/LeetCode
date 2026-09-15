'''
Author: LetMeFly
Date: 2026-09-15 17:12:02
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-15 17:19:06
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x : (x[0], -x[1]))
        ans = len(intervals)
        maxr = -1
        for _, r in intervals:
            if r <= maxr:
                ans -= 1
            else:
                maxr = r
        return ans
