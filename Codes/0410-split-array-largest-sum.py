'''
Author: LetMeFly
Date: 2024-01-21 13:29:22
LastEditors: LetMeFly
LastEditTime: 2024-01-21 13:33:--
'''
from typing import List

class Solution:
    def check(self, k: int, s: int) -> bool:
        cnt = 0
        for t in self.nums:
            if t > s:
                return False
            if cnt + t > s:
                k -= 1
                cnt = 0
            cnt += t
        return k - 1 >= 0

    def splitArray(self, nums: List[int], k: int) -> int:
        self.nums = nums
        l, r = 0, sum(nums) + 1
        while l < r:
            mid = (l + r) >> 1
            if self.check(k, mid):
                r = mid
            else:
                l = mid + 1
        return l