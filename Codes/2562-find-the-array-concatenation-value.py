'''
Author: LetMeFly
Date: 2023-10-12 18:41:47
LastEditors: LetMeFly
LastEditTime: 2023-10-12 18:43:56
'''
from typing import List

class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        ans = 0
        while l < r:
            ans += int(str(nums[l]) + str(nums[r]))
            l, r = l + 1, r - 1
        if l == r:
            ans += nums[l]
        return ans