'''
Author: LetMeFly
Date: 2026-10-11 09:11:24
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-11 09:30:46
'''
from typing import List
from math import isqrt

class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        ans = 0
        for i in range(isqrt(len(nums)) + 1):
            if len(nums) % i == 0:
                ans += nums[i - 1] * nums[i - 1]
                if i * i != len(nums):
                    ans += nums[len(nums) // i - 1] * nums[len(nums) // i - 1]
        return ans
