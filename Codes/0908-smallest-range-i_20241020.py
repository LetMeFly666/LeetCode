'''
Author: LetMeFly
Date: 2024-10-21 14:28:55
LastEditors: LetMeFly
LastEditTime: 2024-10-21 14:29:26
'''
from typing import List

class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        return max(0, max(nums) - min(nums) - 2 * k)