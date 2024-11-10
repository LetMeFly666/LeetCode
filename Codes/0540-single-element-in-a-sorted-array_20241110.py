'''
Author: LetMeFly
Date: 2024-11-10 16:44:54
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-10 17:38:12
'''
from typing import List

class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] == nums[mid ^ 1]:
                l = mid + 1
            else:
                r = mid
        return nums[l]