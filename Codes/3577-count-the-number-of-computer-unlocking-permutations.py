'''
Author: LetMeFly
Date: 2025-12-10 22:34:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-10 22:59:13
'''
from typing import List

class Solution:
    MOD = 1000000007

    def countPermutations(self, complexity: List[int]) -> int:
        ans = 1
        for i in range(1, len(complexity)):
            if complexity[i] <= complexity[0]:
                return 0
            ans = ans * i % self.MOD
        return ans