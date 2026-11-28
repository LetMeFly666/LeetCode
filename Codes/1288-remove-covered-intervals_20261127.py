'''
Author: LetMeFly
Date: 2026-11-27 13:58:14
LastEditors: LetMeFly.xyz
LastEditTime: 2026-11-27 17:04:42
'''
class Solution:
    def removeCoveredIntervals(self, intervals: list[list[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans, maxr = len(intervals), -1
        for _, r in intervals:
            if r <= maxr:
                ans -= 1
            else:
                maxr = r
        return ans
