'''
Author: LetMeFly
Date: 2026-03-27 08:48:57
LastEditors: LetMeFly.xyz
LastEditTime: 2026-03-27 08:58:55
'''
from typing import List

class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        m = len(mat[0])
        return all(row[j] == row[(j + k) % m] for j in range(m) for row in mat)
