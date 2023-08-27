'''
Author: LetMeFly
Date: 2023-08-27 09:02:58
LastEditors: LetMeFly
LastEditTime: 2023-08-27 09:13:02
'''
from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        intervals.append([100000, 100000])
        ans = []
        from_, to = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= to:
                to = max(to, intervals[i][1])
            else:
                ans.append([from_, to])
                from_, to = intervals[i]
        return ans