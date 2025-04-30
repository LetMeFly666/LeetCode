'''
Author: LetMeFly
Date: 2025-04-29 23:46:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-30 10:39:13
'''
from typing import List

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ans = cnt = l = 0
        for r in range(len(nums)):
            cnt += nums[r]
            while cnt * (r - l + 1) >= k:
                cnt -= nums[l]
                l += 1
            ans += (r - l + 1)
        return ans