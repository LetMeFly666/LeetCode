'''
Author: LetMeFly
Date: 2025-07-28 21:39:52
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-28 22:23:33
'''
from typing import List

class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        last = nums[0]
        ans = 0
        # for i, t in enumerate(nums[1:-1]):  # 不可！这样i=0时t=nums[1]
        for i in range(1, len(nums) - 1):
            ans += nums[i] > last and nums[i] > nums[i + 1] or nums[i] < last and nums[i] < nums[i + 1]
            if nums[i] != nums[i + 1]:
                last = nums[i]
        return ans