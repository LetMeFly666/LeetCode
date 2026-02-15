'''
Author: LetMeFly
Date: 2026-02-15 18:09:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-02-15 18:13:14
'''
from typing import List

class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        return [nums[(nums[i] + i) % len(nums)] for i in range(len(nums))]