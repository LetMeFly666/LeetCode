'''
Author: LetMeFly
Date: 2023-10-01 17:56:04
LastEditors: LetMeFly
LastEditTime: 2023-10-01 17:56:58
'''
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        ans, m = 0, prices[0]
        for t in prices:
            m = min(m, t)
            ans = max(ans, t - m)
        return