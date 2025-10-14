'''
Author: LetMeFly
Date: 2025-10-14 20:14:45
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-14 20:24:03
'''
from typing import List

# THIS IS NOT RIGHT
class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        for i in range(len(nums) - 2 * k + 1):
            if all(nums[j + 1] > nums[j] for j in range(i, i + k - 1)) and all(nums[j + 1] > nums[j] for j in range(i + k, i + k * 2 - 1)):
                return True
        return False