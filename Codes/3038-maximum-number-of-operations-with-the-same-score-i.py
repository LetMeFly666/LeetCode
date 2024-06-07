'''
Author: LetMeFly
Date: 2024-06-07 20:21:40
LastEditors: LetMeFly
LastEditTime: 2024-06-07 20:22:25
'''
from typing import List

class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        ans = 1
        val = nums[0] + nums[1]
        for i in range(2, len(nums) - 1, 2):
            if nums[i] + nums[i + 1] != val:
                break
            ans += 1
        return ans