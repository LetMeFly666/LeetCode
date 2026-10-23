'''
Author: LetMeFly
Date: 2026-10-23 20:28:52
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-23 20:32:12
'''
from typing import List

class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        if nums[0]:
            return 0
        ans = -1
        for i, t in enumerate(nums):
            if t != i:
                ans &= i
        return 0 if ans == -1 else ans
