'''
Author: LetMeFly
Date: 2023-10-22 16:47:46
LastEditors: LetMeFly
LastEditTime: 2023-10-22 16:48:51
'''
from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid
            else:
                return mid
        return l