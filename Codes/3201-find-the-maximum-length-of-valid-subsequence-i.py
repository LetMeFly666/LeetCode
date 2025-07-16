'''
Author: LetMeFly
Date: 2025-07-16 13:16:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-16 13:36:53
'''
from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        ans = odd = 0
        last = False if nums[0] % 2 else True
        for t in nums:
            if t % 2:
                odd += 1
                if not last:
                    last = True
                    ans += 1
            else:
                if last:
                    last = False
                    ans += 1
        return max(ans, odd, len(nums) - odd)