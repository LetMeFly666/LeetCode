'''
Author: LetMeFly
Date: 2026-01-25 10:32:52
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-25 10:35:25
'''
from typing import List

# THIS CANNOT BE ACCEPTED
class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        return max(nums[i + k - 1] - nums[i] for i in range(len(nums) - k + 1))