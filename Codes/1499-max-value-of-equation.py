'''
Author: LetMeFly
Date: 2023-07-21 08:04:09
LastEditors: LetMeFly
LastEditTime: 2023-07-21 08:22:57
'''
from typing import List
from collections import deque

class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        ans = -1e9
        q = deque()
        for x, y in points:
            if q and x - q[0][1] > k:
                q.popleft()
            if q:
                ans = max(ans, x + y + q[0][0])
            while q and q[-1][0] <= y - x:
                q.pop()
            q.append([y - x, x])
        return ans