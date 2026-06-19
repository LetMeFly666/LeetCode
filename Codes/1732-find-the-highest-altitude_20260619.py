'''
Author: LetMeFly
Date: 2026-06-19 10:15:51
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-19 10:19:06
'''
from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans = now = 0
        for t in gain:
            now += t
            ans = max(ans, now)
        return ans
