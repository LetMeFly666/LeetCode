'''
Author: LetMeFly
Date: 2023-12-18 14:23:58
LastEditors: LetMeFly
LastEditTime: 2023-12-18 14:25:53
'''
from typing import List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) >> 1
            if (mid - 1 < 0 or nums[mid - 1] < nums[mid]) and (mid + 1 == len(nums) or nums[mid + 1] < nums[mid]):
                return mid
            if mid - 1 < 0 or nums[mid - 1] < nums[mid]:
                l = mid + 1
            else:
                r = mid
        return -1