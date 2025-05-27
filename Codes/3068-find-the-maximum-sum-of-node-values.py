'''
Author: LetMeFly
Date: 2025-05-27 23:28:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-27 23:40:11
'''
from typing import List

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        odd, even = -100000000000000, 0
        for t in nums:
            odd, even = max(odd + t, even + (t ^ k)), max(even + t, odd + (t ^ k))