'''
Author: LetMeFly
Date: 2025-03-21 15:21:19
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-21 15:27:03
'''
from typing import List

class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        allOr = all1 = 0
        for t in nums:
            all1 |= t & allOr
            allOr |= t
        ans = 0
        for t in nums:
            ans = max(ans, t ^ allOr | all1 | t << k)
        return ans
    