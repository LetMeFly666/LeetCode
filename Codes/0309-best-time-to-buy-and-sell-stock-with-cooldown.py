'''
Author: LetMeFly
Date: 2023-10-05 10:49:06
LastEditors: LetMeFly
LastEditTime: 2023-10-05 10:50:34
'''
from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        buy, sell, sellBefore = -prices[0], 0, 0
        for i in range(1, len(prices)):
            buy, sell, sellBefore = max(buy, sellBefore - prices[i]), max(sell, buy + prices[i]), sell
        return sell