'''
Author: LetMeFly
Date: 2023-10-22 16:09:37
LastEditors: LetMeFly
LastEditTime: 2023-10-22 16:13:08
'''
from typing import List
from bisect import bisect_right


class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction.sort()
        positiveLocation = bisect_right(satisfaction, 0)
        ans, sumPositive = 0, 0
        for i in range(positiveLocation, len(satisfaction)):
            ans += (i - positiveLocation + 1) * satisfaction[i]
            sumPositive += satisfaction[i]
        sumNegative = 0
        for i in range(positiveLocation - 1, -1, -1):
            sumNegative += satisfaction[i]
            if -sumNegative > sumPositive:
                break
            ans += sumPositive + sumNegative
        return ans
