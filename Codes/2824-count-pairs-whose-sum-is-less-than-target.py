'''
Author: LetMeFly
Date: 2023-11-24 11:04:43
LastEditors: LetMeFly
LastEditTime: 2023-11-24 11:11:37
'''
from typing import List

class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        ans = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                ans += nums[i] + nums[j] < target
        return ans