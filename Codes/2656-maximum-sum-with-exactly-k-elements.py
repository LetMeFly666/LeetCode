'''
Author: LetMeFly
Date: 2023-11-15 20:34:51
LastEditors: LetMeFly
LastEditTime: 2023-11-15 20:35:02
'''
from typing import List

class Solution:
    def maximizeSum(self, nums: List[int], k: int) -> int:
        return k * (max(nums) * 2 + k - 1) // 2