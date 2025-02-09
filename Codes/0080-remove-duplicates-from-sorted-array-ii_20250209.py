'''
Author: LetMeFly
Date: 2025-02-09 08:53:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-09 08:55:23
'''
from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow = 1
        for fast in range(2, len(nums)):
            if nums[fast] != nums[slow - 1]:
                slow += 1
                nums[slow] = nums[fast]
        return min(len(nums), slow + 1)