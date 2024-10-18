'''
Author: LetMeFly
Date: 2024-10-18 23:02:03
LastEditors: LetMeFly
LastEditTime: 2024-10-18 23:03:25
'''
from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums) - 2):
            if not nums[i]:
                ans += 1
                nums[i + 1] ^= 1
                nums[i + 2] ^= 1
        return ans if nums[-1] & nums[-2] else -1
