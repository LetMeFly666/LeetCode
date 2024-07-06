'''
Author: LetMeFly
Date: 2024-07-06 10:43:50
LastEditors: LetMeFly
LastEditTime: 2024-07-06 10:45:15
'''
from typing import List

class Solution:
    def countAlternatingSubarrays(self, nums: List[int]) -> int:
        ans = 0
        from_ = 0
        for to in range(1, len(nums) + 1):
            if to == len(nums) or nums[to] == nums[to - 1]:
                length = to - from_
                ans += (1 + length) * length // 2
                from_ = to
        return ans