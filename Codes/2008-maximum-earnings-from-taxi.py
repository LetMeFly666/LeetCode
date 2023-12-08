'''
Author: LetMeFly
Date: 2023-12-08 23:11:40
LastEditors: LetMeFly
LastEditTime: 2023-12-08 23:14:37
'''
from typing import List
from collections import defaultdict

class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        ma =  defaultdict(list)
        for ride in rides:
            ma[ride[1]].append(ride)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            dp[i] = dp[i - 1]
            for start, end, tip in ma[i]:
                dp[i] = max(dp[i], dp[start] + end - start + tip)
        return dp[-1]
