'''
Author: LetMeFly
Date: 2026-01-20 22:50:06
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-20 22:55:49
'''
from typing import List

class Solution:
    def get(self, n: int) -> int:
        for i in range(n):
            if (i | (i + 1)) == n:  # 不是(i or (i + 1))
                return i
        return -1
    
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        return [self.get(t) for t in nums]