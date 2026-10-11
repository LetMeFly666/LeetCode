'''
Author: LetMeFly
Date: 2026-10-11 09:02:48
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-11 09:07:21
'''
from typing import List

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        ans = 0
        for i, t in enumerate(nums):
            if not len(nums) % (i + 1):
                ans += t * t
        return ans
