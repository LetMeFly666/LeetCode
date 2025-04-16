'''
Author: LetMeFly
Date: 2025-04-16 20:23:21
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-16 20:26:37
'''
from typing import List
from collections import defaultdict


class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        times = defaultdict(int)
        ans = l = now = 0
        for t in nums:
            now += times[t]
            times[t] += 1
            while now >= k:
                times[nums[l]] -= 1
                now -= times[nums[l]]
                l += 1
            ans += l
        return ans