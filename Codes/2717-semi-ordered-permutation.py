'''
Author: LetMeFly
Date: 2024-12-11 23:19:01
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-11 23:20:07
'''
from typing import List

class Solution:
    def semiOrderedPermutation(self, nums: List[int]) -> int:
        a = b = 0
        for i in range(len(nums)):
            if nums[i] == 1:
                a = i
            elif nums[i] == len(nums):
                b = i
        return a + (len(nums) - 1 - b) - (a > b)