'''
Author: LetMeFly
Date: 2024-09-04 12:42:10
LastEditors: LetMeFly
LastEditTime: 2024-09-04 12:59:02
'''
from typing import List

class Solution:
    def countWays(self, nums: List[int]) -> int:
        nums.sort()
        ans = 1 + (nums[0] != 0)
        for i in range(1, len(nums)):
            ans += i > nums[i - 1] and i < nums[i]
        return ans