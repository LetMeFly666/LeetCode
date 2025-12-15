'''
Author: LetMeFly
Date: 2025-12-15 13:32:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-15 18:54:39
'''
from typing import List

class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        ans = last = cnt = 0
        for p in prices:
            if p != last - 1:
                ans += cnt * (cnt + 1) // 2
                cnt = 0
            cnt += 1
            last = p
        return ans + cnt * (cnt + 1) // 2
