'''
Author: LetMeFly
Date: 2023-07-11 08:22:18
LastEditors: LetMeFly
LastEditTime: 2023-07-11 08:36:32
'''
from typing import List

class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        even, odd = nums[0], 0
        for i in range(1, len(nums)):
            even = max(even, odd + nums[i])
            odd = max(odd, even - nums[i])
        return even