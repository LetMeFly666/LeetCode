'''
Author: LetMeFly
Date: 2025-05-10 12:07:54
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-10 19:29:26
'''
from typing import List, Tuple

class Solution:
    def cal1(self, nums: List[int]) -> Tuple[int, int]:
        s, c = 0, 0
        for t in nums:
            if t:
                s += t
            else:
                c += 1
        return s, c
    
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1, c1 = self.cal1(nums1)
        s2, c2 = self.cal2(nums2)
        if s1 < s2 + c2 and c1 == 0 or s1 + c1 > s2 and c2 == 0:
            return -1
        return max(s1 + c1, s2 + c2)