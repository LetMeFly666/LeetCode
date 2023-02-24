'''
Author: LetMeFly
Date: 2023-02-24 08:48:48
LastEditors: LetMeFly
LastEditTime: 2023-02-24 08:50:21
'''
from typing import List

class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        se = set()
        for t in nums:
            if t:
                se.add(t)
        return len(se)