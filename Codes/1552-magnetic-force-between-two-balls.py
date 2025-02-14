'''
Author: LetMeFly
Date: 2025-02-14 10:56:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-14 10:58:23
'''
from typing import List

class Solution:
    def check(self, m: int, d: int) -> bool:
        last = -1000000000
        for t in self.position:
            if t - last >= d:
                m -= 1
                if not m:
                    return True
                last = t
        return False
    
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        self.position = position
        l, r = 1, position[-1] - position[0]
        while l < r:
            mid = (l + r + 1) >> 1
            if self.check(m, mid):
                l = mid
            else:
                r = mid - 1
        return l