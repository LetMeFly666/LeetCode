'''
Author: LetMeFly
Date: 2025-05-06 21:30:01
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-06 21:34:14
'''
from typing import List

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        for i in range(len(nums)):
            ans[i] = nums[nums[i]]
        return ans