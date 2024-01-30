'''
Author: LetMeFly
Date: 2024-01-30 12:00:59
LastEditors: LetMeFly
LastEditTime: 2024-01-30 12:03:07
'''
from typing import List
from collections import defaultdict

class Solution:
    def minimumSeconds(self, nums: List[int]) -> int:
        ma = defaultdict(list)
        for i, val in enumerate(nums):
            ma[val].append(i)
        ans = len(nums) - 1
        for num, positions in ma.items():
            thisMax = positions[0] + len(nums) - positions[-1]
            for i in range(1, len(positions)):
                thisMax = max(thisMax, positions[i] - positions[i - 1])
            ans = min(ans, thisMax // 2)
        return ans