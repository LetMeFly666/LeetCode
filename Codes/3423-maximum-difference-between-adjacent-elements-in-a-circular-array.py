'''
Author: LetMeFly
Date: 2025-06-12 22:49:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-12 22:53:39
'''
from typing import List

class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        ans = abs(nums[0] - nums[-1])
        for i in range(1, len(nums)):
            ans = max(ans, abs(nums[i] - nums[i - 1]))
        return ans