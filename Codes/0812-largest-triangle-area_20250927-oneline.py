'''
Author: LetMeFly
Date: 2025-09-27 12:53:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-27 15:17:57
'''
from typing import List
from itertools import combinations

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max(abs((p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0])) for p1, p2, p3 in combinations(points, 3)) / 2