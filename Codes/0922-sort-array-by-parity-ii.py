'''
Author: LetMeFly
Date: 2025-02-04 22:25:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-04 22:26:17
'''
from typing import List

class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        i, j = 0, 1
        while i < len(nums):
            if nums[i] % 2 == 0:
                i += 2
            elif nums[j] % 2:
                j += 2
            else:
                nums[i], nums[j] = nums[j], nums[i]
                i += 2
                j += 2
        return nums