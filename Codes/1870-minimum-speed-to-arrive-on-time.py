'''
Author: LetMeFly
Date: 2024-10-02 13:07:46
LastEditors: LetMeFly
LastEditTime: 2024-10-02 13:16:20
'''
from typing import List

class Solution:
    def ok(self, speed) -> bool:
        t = 0
        for i in range(len(self.dist) - 1):
            t += (self.dist[i] + speed - 1) // speed
        return (self.hour - t * 100) * speed >= self.dist[-1] * 100
    
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        self.dist = dist
        self.hour = round(hour * 100)
        l, r = 1, int(1e7) + 1
        while l < r:
            mid = (l + r) >> 1
            if self.ok(mid):
                r = mid
            else:
                l = mid + 1
        return -1 if l == int(1e7) + 1 else l
