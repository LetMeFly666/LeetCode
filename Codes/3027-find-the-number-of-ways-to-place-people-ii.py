'''
Author: LetMeFly
Date: 2025-09-05 09:55:20
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-05 10:35:32
'''
from typing import List

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: (x[0], -x[1]))
        ans = 0
        for i in range(len(points)):
            mxY = -1000000001
            for j in range(i + 1, len(points)):
                if mxY < points[j][1] <= points[i][1]:
                    mxY = points[j][1]
                    ans += 1
        return ans