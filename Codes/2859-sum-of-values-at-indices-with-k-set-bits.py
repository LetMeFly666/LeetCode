'''
Author: LetMeFly
Date: 2024-01-25 09:01:07
LastEditors: LetMeFly
LastEditTime: 2024-01-25 09:08:54
'''
from typing import List

class Solution:
    def sumIndicesWithKSetBits(self, nums: List[int], k: int) -> int:
        return sum(nums[i] if bin(i).count('1') == k else 0 for i in range(len(nums)))