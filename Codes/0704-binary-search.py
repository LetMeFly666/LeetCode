'''
Author: LetMeFly
Date: 2023-10-06 13:04:33
LastEditors: LetMeFly
LastEditTime: 2023-10-06 13:06:05
'''
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums)
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > target:
                r = mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                return mid
        return -1