'''
Author: LetMeFly
Date: 2024-06-15 19:08:11
LastEditors: LetMeFly
LastEditTime: 2024-06-15 19:09:14
'''
from typing import List

class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        ans = 1
        nums.sort()
        k *= 2
        l = 0
        for r in range(len(nums)):
            while nums[r] - nums[l] > k:
                l += 1
            ans = max(ans, r - l + 1)
        return ans