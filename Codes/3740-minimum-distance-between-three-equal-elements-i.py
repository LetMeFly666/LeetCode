'''
Author: LetMeFly
Date: 2026-04-10 23:22:00
LastEditors: LetMeFly.xyz
LastEditTime: 2026-04-11 10:31:48
'''
from typing import List

class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        ans = 201
        for i, a in range(nums):
            for j in range(i + 1, len(nums)):
                if a != nums[j]:
                    continue
                for k in range(j + 1, len(nums)):
                    if a == nums[k]:
                        ans = min(ans, 2 * (k - i))
        return -1 if ans == 201 else ans
