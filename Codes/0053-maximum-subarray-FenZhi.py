'''
Author: LetMeFly
Date: 2023-11-20 11:07:51
LastEditors: LetMeFly
LastEditTime: 2023-11-20 11:16:29
'''
"""为何不用切片作为参数？
>>> a = [1, 2, 3]
>>> a
[1, 2, 3]
>>> b = a[1:2]
>>> b
[2]
>>> b[0] = 99
>>> a
[1, 2, 3]
>>> b
[99]
"""
from typing import List


class Status:
    def __init__(self, lSum: int, rSum: int, MSum: int, iSum: int) -> None:
        self.lSum = lSum
        self.rSum = rSum
        self.MSum = MSum
        self.iSum = iSum


class Solution:
    def get(self, nums: List[int], l: int, r: int) -> Status:
        if l == r:
            return Status(nums[l], nums[l], nums[l], nums[l])
        m = (l + r) >> 1
        lStatus = self.get(nums, l, m)
        rStatus = self.get(nums, m + 1, r)
        return Status(
            max(lStatus.lSum, lStatus.iSum + rStatus.lSum),
            max(rStatus.rSum, lStatus.rSum + rStatus.iSum),
            max(lStatus.MSum, rStatus.MSum, lStatus.rSum + rStatus.lSum),
            lStatus.iSum + rStatus.iSum
        )
    
    def maxSubArray(self, nums: List[int]) -> int:
        return self.get(nums, 0, len(nums) - 1).MSum
