'''
Author: LetMeFly
Date: 2026-07-18 07:44:07
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-18 07:52:01
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = len(intervals)
        maxr = 0
        for _, b in intervals:
            if b <= maxr:
                ans -= 1
            else:
                maxr = b
        return ans
