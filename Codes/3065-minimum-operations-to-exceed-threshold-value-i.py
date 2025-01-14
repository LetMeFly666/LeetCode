'''
Author: LetMeFly
Date: 2025-01-14 12:31:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-14 12:31:38
'''
from typing import List

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(t < k for t in nums)