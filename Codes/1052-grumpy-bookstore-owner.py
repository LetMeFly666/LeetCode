'''
Author: LetMeFly
Date: 2024-04-23 12:34:23
LastEditors: LetMeFly
LastEditTime: 2024-04-23 12:38:13
'''
from typing import List

class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        thisAns = sum(customers[i] for i in range(minutes)) + sum(customers[i] if not grumpy[i] else 0 for i in range(minutes, len(customers)))
        ans = thisAns
        for r in range(minutes, len(customers)):
            thisAns += customers[r] * grumpy[r] - customers[r - minutes] * grumpy[r - minutes]
            ans = max(ans, thisAns)
        return ans
