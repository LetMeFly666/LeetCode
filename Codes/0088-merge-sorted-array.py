'''
Author: LetMeFly
Date: 2023-08-13 07:59:15
LastEditors: LetMeFly
LastEditTime: 2023-08-13 08:45:36
'''
from typing import List

class Solution:
    def merge(self, nums1: List[int], l1: int, nums2: List[int], l2: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        l = l1 + l2 - 1
        l1, l2 = l1 - 1, l2 - 1
        while l2 >= 0:
            while l1 >= 0 and nums1[l1] > nums2[l2]:
                nums1[l] = nums1[l1]
                l, l1 = l - 1, l1 - 1
            nums1[l] = nums2[l2]
            l, l2 = l - 1, l2 - 1