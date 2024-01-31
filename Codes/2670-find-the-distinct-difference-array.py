'''
Author: LetMeFly
Date: 2024-01-31 11:19:53
LastEditors: LetMeFly
LastEditTime: 2024-01-31 11:21:18
'''
from typing import List

class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        se = set()
        suffix = [0] * (len(nums) + 1)
        for i in range(len(nums) - 1, -1, -1):
            se.add(nums[i])
            suffix[i] = len(se)
        se.clear()
        ans = [0] * len(nums)
        for i in range(len(nums)):
            se.add(nums[i])
            ans[i] = len(se) - suffix[i + 1]
        return ans