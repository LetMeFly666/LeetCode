'''
Author: LetMeFly
Date: 2024-05-18 15:37:43
LastEditors: LetMeFly
LastEditTime: 2024-05-18 15:40:52
'''
from typing import List

class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        M, ans = -1, 0
        for d in divisors:
            thisCnt = 0
            for n in nums:
                thisCnt += n % d == 0
            if thisCnt > M:
                M = thisCnt
                ans = d
            elif thisCnt == M:
                ans = min(ans, d)
        return ans