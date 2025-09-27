'''
Author: LetMeFly
Date: 2025-09-27 12:53:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-27 15:15:55
'''
from typing import List
from itertools import combinations

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        ans = 0
        for p1, p2, p3 in combinations(points, 3):
            x1, y1 = p2[0] - p1[0], p2[1] - p1[1]
            x2, y2 = p3[0] - p1[0], p3[1] - p1[1]
            ans = max(ans, abs(x1 * y2 - y1 * x2))  # 记得abs
        return ans / 2