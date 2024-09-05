'''
Author: LetMeFly
Date: 2024-09-03 18:24:08
LastEditors: LetMeFly
LastEditTime: 2024-09-03 18:31:17
'''
from typing import List

class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        M, m = nums[0], nums[0]
        for i in range(1, len(nums)):
            M, m = max(M, nums[i], M * nums[i], m * nums[i]), \
                   min(m, nums[i], M * nums[i], m * nums[i])
        return M