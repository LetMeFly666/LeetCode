'''
Author: LetMeFly
Date: 2025-05-21 23:06:35
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-21 23:19:48
'''
from typing import List

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        diff = [0] * (len(nums) + 1)
        for l, r in queries:
            diff[l] += 1
            diff[r + 1] -= 1
        cnt = 0
        for i in range(len(nums)):
            cnt += diff[i]
            if nums[i] > cnt:
                return False
        return True