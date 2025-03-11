'''
Author: LetMeFly
Date: 2025-03-11 14:04:02
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-11 14:07:14
'''
from typing import List

class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        mx = [0] * len(nums)
        mn = [0] * len(nums)
        now = 0
        for i in range(len(nums)):
            mx[i] = now = max(now, nums[i])
        now = 1000000
        for i in range(len(nums) - 1, -1, -1):
            mn[i] = now = min(now, nums[i])
        ans = 0
        for i in range(1, len(nums) - 1):
            if mx[i - 1] < nums[i] < mn[i + 1]:
                ans += 2
            elif nums[i - 1] < nums[i] < nums[i + 1]:
                ans += 1
        return ans