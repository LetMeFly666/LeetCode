'''
Author: LetMeFly
Date: 2024-10-10 12:19:59
LastEditors: LetMeFly
LastEditTime: 2024-10-10 12:20:10
'''
from typing import List

class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        return sum(n1 % (n2 * k) == 0 for n2 in nums2 for n1 in nums1)