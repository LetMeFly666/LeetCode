'''
Author: LetMeFly
Date: 2026-10-06 11:45:51
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-06 11:54:43
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(lambda x: (x[0], -x[1]))
        ans, maxr = 0, -1
        for _, r in intervals:
            if r <= maxr:
                ans -= 1
            else:
                maxr = r
        return ans
