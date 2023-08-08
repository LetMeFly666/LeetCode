'''
Author: LetMeFly
Date: 2023-08-08 07:58:55
LastEditors: LetMeFly
LastEditTime: 2023-08-08 07:58:56
'''
from typing import List

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        ans, m, M = abs(nums[0]), nums[0], nums[0]
        for i in range(1, len(nums)):
            M = max(nums[i], M + nums[i])
            m = min(nums[i], m + nums[i])
            ans = max(ans, M, -m)
        return ans