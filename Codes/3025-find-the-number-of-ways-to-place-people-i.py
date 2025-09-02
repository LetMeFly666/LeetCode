'''
Author: LetMeFly
Date: 2025-09-02 13:08:07
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-02 18:47:49
'''
from typing import List

class Solution:
    def check2(self, i: int, j: int) -> bool:
        return self.points[i][0] <= self.points[j][0] and self.points[i][1] >= self.points[j][1]
    
    def check3(self, i: int, j: int, k: int) -> bool:
        return not (self.points[i][0] <= self.points[k][0] <= self.points[j][0] and self.points[i][1] >= self.points[k][1] >= self.points[j][1])
    
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        n = len(points)
        self.points = points
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if not self.check2(i, j):
                    continue
                can = True
                for k in range(n):
                    if k == i or k == j:
                        continue
                    if not self.check3(i, j, k):
                        can = False
                        break
                ans += can
        return ans