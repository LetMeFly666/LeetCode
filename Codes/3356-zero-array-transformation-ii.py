'''
Author: LetMeFly
Date: 2025-05-22 22:07:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-22 23:27:03
'''
from typing import List

class Solution:
    def check(self, n: int) -> bool:
        diff = [0] * (len(self.nums) + 1)
        for l, r, v in self.queries[:n]:
            diff[l] += v
            diff[r + 1] -= v
        cnt = 0
        for i in range(len(self.nums)):
            cnt += diff[i]
            if self.nums[i] > cnt:
                return False
        return True

    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        self.nums = nums
        self.queries = queries
        l, r = -1, len(queries) + 1
        while l + 1 < r:
            m = (l + r) >> 1
            if self.check(m):
                r = m
            else:
                l = m
        return -1 if r > len(queries) else r