'''
Author: LetMeFly
Date: 2025-02-13 13:42:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-13 13:44:17
'''
from typing import List

class Solution:
    def check(self, op: int, m: int) -> bool:
        for t in self.nums:
            op -= (t - 1) // m
        return op >= 0
    
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        self.nums = nums
        l, r = 1, max(nums)
        while l < r:
            m = (l + r) >> 1
            if self.check(maxOperations, m):
                r = m
            else:
                l = m + 1
        return r