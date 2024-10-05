'''
Author: LetMeFly
Date: 2024-10-05 18:16:03
LastEditors: LetMeFly
LastEditTime: 2024-10-05 18:19:09
'''
from typing import List

class Solution:
    def check(self, timeCnt: int) -> bool:
        return sum(timeCnt // t for t in self.time) >= self.totalTrips
    
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        self.time, self.totalTrips = time, totalTrips
        l, r = 1, int(1e14) + 1
        while l < r:
            mid = (l + r) >> 1
            if self.check(mid):
                r = mid
            else:
                l = mid + 1
        return l
