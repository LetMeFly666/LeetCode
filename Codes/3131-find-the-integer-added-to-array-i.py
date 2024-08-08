'''
Author: LetMeFly
Date: 2024-08-08 22:15:51
LastEditors: LetMeFly
LastEditTime: 2024-08-08 22:15:53
'''
from typing import List

class Solution:
    def addedInteger(self, nums1: List[int], nums2: List[int]) -> int:
        return min(nums2) - min(nums1)