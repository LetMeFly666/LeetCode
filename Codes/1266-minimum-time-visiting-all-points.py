'''
Author: LetMeFly
Date: 2026-01-12 23:24:06
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-12 23:32:26
'''
from typing import List
from itertools import pairwise

class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        return sum(max(abs(a[0] - b[0]), abs(a[1] - b[1])) for a, b in pairwise(points))