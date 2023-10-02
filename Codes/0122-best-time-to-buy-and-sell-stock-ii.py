'''
Author: LetMeFly
Date: 2023-10-02 14:03:15
LastEditors: LetMeFly
LastEditTime: 2023-10-02 14:04:23
'''
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        return sum(max(0, prices[i] - prices[i - 1]) for i in range(1, len(prices)))