'''
Author: LetMeFly
Date: 2025-04-18 10:26:49
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-18 10:28:15
'''
from typing import List
from collections import defaultdict

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        times = defaultdict(int)
        ans = len(nums) * (len(nums) - 1) // 2
        for i, v in enumerate(nums):
            ans -= times[v - i]
            times[v - i] += 1
        return ans