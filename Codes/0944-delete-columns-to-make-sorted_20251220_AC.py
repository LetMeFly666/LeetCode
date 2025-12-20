'''
Author: LetMeFly
Date: 2025-12-20 22:44:28
LastEditors: LetMeFly.xyz
LastEditTime: 2025-12-20 22:55:49
'''
from typing import List

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        return sum(any(strs[i][j] < strs[i-1][j] for i in range(1, len(strs))) for j in range(len(strs[0])))