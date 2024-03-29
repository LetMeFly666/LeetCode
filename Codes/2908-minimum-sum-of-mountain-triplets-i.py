'''
Author: LetMeFly
Date: 2024-03-29 17:10:43
LastEditors: LetMeFly
LastEditTime: 2024-03-29 17:12:39
'''
from typing import List

class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        leftMin = [0] * len(nums)
        leftMin[0] = nums[0]
        for i in range(1, len(nums)):
            leftMin[i] = min(leftMin[i - 1], nums[i])
        rightMin = nums[-1]
        ans = 1_000_000
        for i in range(len(nums) - 2, 0, -1):
            if nums[i] > leftMin[i - 1] and nums[i] > rightMin:
                ans = min(ans, nums[i] + leftMin[i - 1] + rightMin)
            rightMin = min(rightMin, nums[i])
        return ans if ans < 1_000_000 else -1