'''
Author: LetMeFly
Date: 2023-10-06 12:12:14
LastEditors: LetMeFly
LastEditTime: 2023-10-06 12:13:34
'''
from typing import List

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy, sell = -prices[0], 0
        for i in range(1, len(prices)):
            buy = max(buy, sell - prices[i])
            sell = max(sell, buy + prices[i] - fee)
        return sell