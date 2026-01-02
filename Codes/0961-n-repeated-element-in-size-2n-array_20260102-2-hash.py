'''
Author: LetMeFly
Date: 2026-01-02 17:01:31
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-02 17:01:39
'''
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        visited = set()
        for t in nums:
            if t in visited:
                return t
            visited.add(t)