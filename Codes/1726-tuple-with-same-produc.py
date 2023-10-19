'''
Author: LetMeFly
Date: 2023-10-19 10:16:10
LastEditors: LetMeFly
LastEditTime: 2023-10-19 10:18:40
'''
from collections import Counter
from typing import List

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        return sum([v * (v - 1) * 4 for _, v in Counter([nums[i] * nums[j] for i in range(len(nums)) for j in range(i + 1, len(nums))]).items()])