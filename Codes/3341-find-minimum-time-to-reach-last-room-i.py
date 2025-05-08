'''
Author: LetMeFly
Date: 2025-05-07 23:27:54
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-07 23:49:02
'''
from typing import List
import heapq

DIRECTIONS = [[0, 1], [0, -1], [1, 0], [-1, 0]]

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n, m = len(moveTime), len(moveTime[0])
        time = [[2000000000] * m for _ in range(n)]
        time[0][0] = 0
        pq = [(0, 0, 0)]
        while pq:
            t, x, y = heapq.heappop(pq)
            if t > time[x][y]:
                continue
            for dx, dy in DIRECTIONS:
                nx, ny = x + dx, y + dy
                if not(0 <= nx < n and 0 <= ny < m):
                    continue
                nt = max(t, moveTime[nx][ny]) + 1
                if nt < time[nx][ny]:
                    time[nx][ny] = nt
                    heapq.heappush(pq, (nt, nx, ny))
        return time[n - 1][m - 1]