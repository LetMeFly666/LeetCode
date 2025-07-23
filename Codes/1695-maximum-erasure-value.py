'''
Author: LetMeFly
Date: 2025-07-23 10:31:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-23 13:29:36
'''
from typing import List

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        had = set()
        ans = l = cnt = 0
        for v in nums:
            while v in had:
                had.remove(nums[l])
                cnt -= nums[l]
                l += 1
            had.add(v)
            cnt += v
            ans = max(ans, cnt)
        return ans