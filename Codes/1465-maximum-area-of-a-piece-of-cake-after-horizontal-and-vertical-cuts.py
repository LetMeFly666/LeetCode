'''
Author: LetMeFly
Date: 2023-10-27 12:30:02
LastEditors: LetMeFly
LastEditTime: 2023-10-27 12:33:31
'''
from typing import List

class Solution:
    def getMax(self, l: int, v: List[int]) -> int:
        v.sort()
        ans = v[0]
        for i in range(1, len(v)):
            ans = max(ans, v[i] - v[i - 1])
        return max(ans, l - v[-1])

    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        return self.getMax(h, horizontalCuts) * self.getMax(w, verticalCuts) % 1000000007