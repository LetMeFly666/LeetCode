'''
Author: LetMeFly
Date: 2024-04-08 12:11:01
LastEditors: LetMeFly
LastEditTime: 2024-04-08 14:46:47
'''
from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        nums = sorted(set(nums))
        ans = n - 1
        r = 0
        for l in range(len(nums)):
            while r < len(nums) and nums[r] <= nums[l] + n - 1:
                r += 1
            ans = min(ans, n - (r - l))
        return ans
