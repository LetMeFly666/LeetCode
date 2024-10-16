'''
Author: LetMeFly
Date: 2024-10-16 23:07:45
LastEditors: LetMeFly
LastEditTime: 2024-10-16 23:07:46
'''
from typing import List

class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        nums.sort()
        ans = 1000
        for i in range(len(nums) // 2):
            ans = min(ans, nums[i] + nums[-(i + 1)])
        return ans / 2