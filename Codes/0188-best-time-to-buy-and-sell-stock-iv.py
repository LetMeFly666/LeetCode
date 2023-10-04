'''
Author: LetMeFly
Date: 2023-10-04 11:04:02
LastEditors: LetMeFly
LastEditTime: 2023-10-04 11:07:00
'''
from typing import List

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:
            return 0
        buy = [-prices[0]] * (k + 1)
        sell = [0] * (k + 1)
        buy[0] = 0
        for i in range(1, len(prices)):
            for j in range(1, k + 1):
                buy[j] = max(buy[j], sell[j - 1] - prices[i])
                sell[j] = max(sell[j], buy[j] + prices[i])
        return sell[k]