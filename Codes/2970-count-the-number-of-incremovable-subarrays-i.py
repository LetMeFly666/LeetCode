'''
Author: LetMeFly
Date: 2024-07-10 00:19:33
LastEditors: LetMeFly
LastEditTime: 2024-07-10 00:21:05
'''
from typing import List

class Solution:
    def isOk(self, l: int, r: int) -> bool:
        last = 0
        for i in range(len(self.nums)):
            if l <= i <= r:
                continue
            if self.nums[i] <= last:
                return False
            last = self.nums[i]
        return True
    
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        self.nums = nums
        ans = 0
        for l in range(len(nums)):
            for r in range(l, len(nums)):
                ans += self.isOk(l, r)
        return ans