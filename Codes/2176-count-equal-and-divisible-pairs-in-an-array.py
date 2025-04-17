'''
Author: LetMeFly
Date: 2025-04-17 20:15:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-17 20:15:58
'''
from typing import List


class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        return sum(nums[i] == nums[j] and i * j % k == 0 for i in range(len(nums)) for j in range(i + 1, len(nums)))