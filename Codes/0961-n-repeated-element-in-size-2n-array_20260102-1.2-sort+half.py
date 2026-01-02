'''
Author: LetMeFly
Date: 2026-01-02 16:59:21
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-02 16:59:27
'''
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        nums.sort()
        mid = len(nums) // 2
        return nums[mid] if nums[mid] == nums[mid + 1] else nums[mid - 1]