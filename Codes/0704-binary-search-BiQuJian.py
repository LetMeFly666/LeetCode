'''
Author: LetMeFly
Date: 2023-10-06 13:04:33
LastEditors: LetMeFly
LastEditTime: 2023-10-06 13:31:26
'''
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] > target:
                r = mid - 1
            elif nums[mid] == target:
                return mid
            else:
                l = mid + 1
        return -1