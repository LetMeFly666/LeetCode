'''
Author: LetMeFly
Date: 2025-07-03 21:31:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-06 00:08:16
'''
from typing import List

class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        idx = [i for i in range(len(nums))]
        idx.sort(lambda i : nums[i])
        idx = idx[:k]
        idx.sort()
        return [nums[i] for i in idx]