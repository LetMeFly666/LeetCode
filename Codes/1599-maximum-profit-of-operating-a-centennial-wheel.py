'''
Author: LetMeFly
Date: 2023-03-05 13:24:20
LastEditors: LetMeFly
LastEditTime: 2023-03-05 13:35:38
'''
from typing import List


class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        ans = 0
        maxEarn = 0
        nowEarn = 0
        customerInLine = 0
        times = 0
        while True:
            if times < len(customers):
                customerInLine += customers[times]
            times += 1
            thisCustomer = min(4, customerInLine)
            customerInLine -= thisCustomer
            nowEarn += thisCustomer * boardingCost - runningCost
            if nowEarn > maxEarn:
                maxEarn = nowEarn
                ans = times
            if not customerInLine and times >= len(customers):
                break
        return ans if ans else -1