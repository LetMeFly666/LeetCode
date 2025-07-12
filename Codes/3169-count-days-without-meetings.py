'''
Author: LetMeFly
Date: 2025-07-11 23:25:31
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-12 12:00:22
'''
from typing import List

class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        ans = last = 0
        meetings.sort()
        for l, r in meetings:
            if l > last + 1:
                ans += l - last - 1
            last = max(last, r)
        ans += days - last
        return ans