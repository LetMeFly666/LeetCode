'''
Author: LetMeFly
Date: 2024-04-09 11:53:54
LastEditors: LetMeFly
LastEditTime: 2024-04-09 12:01:30
'''
from typing import List

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        return max(sum(1 if t > 0 else 0 for t in nums), sum(1 if t < 0 else 0 for t in nums))