'''
Author: LetMeFly
Date: 2025-01-16 12:25:24
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-16 12:27:03
'''
from typing import List

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = 100
        for l in range(len(nums)):
            val = nums[l]
            for r in range(l, len(nums)):
                val |= nums[r]
                if val >= k:
                    ans = min(ans, r - l + 1)
                    break
        return -1 if ans == 100 else ans