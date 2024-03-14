'''
Author: LetMeFly
Date: 2024-03-14 08:55:17
LastEditors: LetMeFly
LastEditTime: 2024-03-14 08:56:09
'''
from typing import List

class Solution:
    def maxArrayValue(self, nums: List[int]) -> int:
        ans = nums[-1]
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] <= ans:
                ans += nums[i]
            else:
                ans = nums[i]
        return ans