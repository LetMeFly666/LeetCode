'''
Author: LetMeFly
Date: 2023-11-24 11:06:38
LastEditors: LetMeFly
LastEditTime: 2023-11-24 11:08:11
'''
from typing import List
from bisect import bisect_left

class Solution:
    def countPairs(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = 0
        for i in range(len(nums)):
            ans += bisect_left(nums[:i], target - nums[i])
        return ans