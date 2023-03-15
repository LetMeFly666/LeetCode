'''
Author: LetMeFly
Date: 2023-03-15 10:42:17
LastEditors: LetMeFly
LastEditTime: 2023-03-15 10:43:52
'''
from typing import List


class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        for i in range(0, len(nums), 2):
            ans += nums[i]
        return ans