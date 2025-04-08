'''
Author: LetMeFly
Date: 2025-04-08 21:55:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-08 21:57:08
'''
from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        se = set()
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] in se:
                return i // 3 + 1
            se.add(nums[i])
        return 0