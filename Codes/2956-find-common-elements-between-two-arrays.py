'''
Author: LetMeFly
Date: 2024-07-16 23:27:21
LastEditors: LetMeFly
LastEditTime: 2024-07-16 23:27:22
'''
from typing import List

class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return [sum(t in nums2 for t in nums1), sum(t in nums1 for t in nums2)]