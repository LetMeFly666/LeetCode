'''
Author: LetMeFly
Date: 2024-09-12 21:21:22
LastEditors: LetMeFly
LastEditTime: 2024-09-12 21:23:23
'''
from typing import List

class Solution:
    def maxNumOfMarkedIndices(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        l, r = 0, (len(nums) + 1) // 2
        while r < len(nums):
            if nums[l] * 2 <= nums[r]:
                ans += 2
                l += 1
            r += 1
        return ans