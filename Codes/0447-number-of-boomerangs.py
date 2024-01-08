'''
Author: LetMeFly
Date: 2024-01-08 19:14:15
LastEditors: LetMeFly
LastEditTime: 2024-01-08 19:15:58
'''
from typing import List
from collections import defaultdict

class Solution:
    def numberOfBoomerangs(self, points: List[List[int]]) -> int:
        ans = 0
        for p in points:
            ma = defaultdict(int)
            for q in points:
                ma[(p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1])] += 1
            for _, cnt in ma.items():
                ans += cnt * (cnt - 1)
        return ans