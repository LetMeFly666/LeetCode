'''
Author: LetMeFly
Date: 2025-01-20 13:31:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-20 13:32:00
'''
from typing import List

class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        ans = nums[0]
        for t in nums:
            if abs(t) < abs(ans) or abs(t) == abs(ans) and ans < 0:
                ans = t
        return ans