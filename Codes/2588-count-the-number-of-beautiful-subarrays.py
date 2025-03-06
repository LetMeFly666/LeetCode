'''
Author: LetMeFly
Date: 2025-03-06 16:35:13
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-06 16:36:59
'''
from typing import List
from collections import defaultdict

class Solution:
    def beautifulSubarrays(self, nums: List[int]) -> int:
        times = defaultdict(int)
        times[0] = 1
        ans = val = 0
        for t in nums:
            val ^= t
            ans += times[val]
            times[val] += 1
        return ans