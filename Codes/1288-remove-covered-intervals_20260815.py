'''
Author: LetMeFly
Date: 2026-08-15 10:09:19
LastEditors: LetMeFly.xyz
LastEditTime: 2026-08-15 10:27:14
'''
from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans, maxr = len(intervals), 0
        for _, e in intervals:  # 看来语言写多了就是容易弄混
            if maxr >= e:
                ans -= 1
            else:
                maxr = e
        return ans
