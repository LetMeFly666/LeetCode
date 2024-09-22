'''
Author: LetMeFly
Date: 2024-09-21 14:10:54
LastEditors: LetMeFly
LastEditTime: 2024-09-21 14:21:17
'''
from typing import List

class Solution:
    def edgeScore(self, edges: List[int]) -> int:
        scores = [0] * len(edges)
        M, ans = 0, -1
        for edge, th in enumerate(edges):
            scores[th] += edge
            if scores[th] > M or scores[th] == M and th < ans:
                M, ans = scores[th], th
        return ans
