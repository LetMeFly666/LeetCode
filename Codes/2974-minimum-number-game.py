'''
Author: LetMeFly
Date: 2024-07-12 00:23:49
LastEditors: LetMeFly
LastEditTime: 2024-07-12 00:24:38
'''
from typing import List

class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        for i in range(0, len(nums) - 1, 2):
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
        return nums