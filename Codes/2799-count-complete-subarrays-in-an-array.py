'''
Author: LetMeFly
Date: 2025-04-24 22:47:44
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-24 23:10:14
Description: AC,60.65%,29.08%
'''
from typing import List
from collections import defaultdict

class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        allType = len(set(nums))
        times = defaultdict(int)
        l = ans = 0
        for r in range(len(nums)):
            times[nums[r]] += 1
            while len(times) == allType and times[nums[l]] > 1:
                times[nums[l]] -= 1
                l += 1
            if len(times) == allType:
                ans += l + 1
        return ans