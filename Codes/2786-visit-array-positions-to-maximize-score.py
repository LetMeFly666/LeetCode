'''
Author: LetMeFly
Date: 2024-06-14 19:01:46
LastEditors: LetMeFly
LastEditTime: 2024-06-14 19:03:16
'''
from typing import List

class Solution:
    def maxScore(self, nums: List[int], x: int) -> int:
        odd, even = 0 if nums[0] % 2 else -x, -x if nums[0] % 2 else 0
        for t in nums:
            if t % 2:
                odd = max(odd + t, even + t - x)
            else:
                even = max(odd + t - x, even + t)
        return max(even, odd)