'''
Author: LetMeFly
Date: 2023-12-17 16:56:55
LastEditors: LetMeFly
LastEditTime: 2023-12-17 16:58:09
'''
from typing import List

class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cost.append(0)
        for i in range(2, len(cost)):
            cost[i] += min(cost[i - 1], cost[i - 2])
        return cost[-1]