'''
Author: LetMeFly
Date: 2023-09-15 09:19:54
LastEditors: LetMeFly
LastEditTime: 2023-09-15 09:22:52
'''
from typing import List

class Solution:
    def giveGem(self, gem: List[int], operations: List[List[int]]) -> int:
        for a, b in operations:
            change = gem[a] // 2
            gem[a] -= change
            gem[b] += change
        return max(gem) - min(gem)
