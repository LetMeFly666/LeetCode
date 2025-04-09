'''
Author: LetMeFly
Date: 2025-04-09 22:09:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-09 22:10:06
'''
from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        if nums[-1] < k:
            return -1
        ans = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                ans += 1
        return ans + (nums[-1] != k)