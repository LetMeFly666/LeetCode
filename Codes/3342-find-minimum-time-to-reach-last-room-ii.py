'''
Author: LetMeFly
Date: 2025-05-09 12:45:04
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-09 13:38:28
'''
from typing import List
import heapq

DIRECTIONS = [[0, 1], [0, -1], [-1, 0], [1, 0]]

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n, m = len(moveTime), len(moveTime[0])
        ans = [[2000000001] * m for _ in range(n)]
        ans[0][0] = 0
        pq = [(0, 0, 0)]
        while pq:
            t, x, y = heapq.heappop(pq)
            if t > ans[x][y]:
                continue
            for dx, dy in DIRECTIONS:
                nx = x + dx
                ny = y + dy
                if not (0 <= nx < n and 0 <= ny < m):
                    continue
                nt = max(t, moveTime[nx][ny]) + (x + y) % 2 + 1
                if nt < ans[nx][ny]:
                    ans[nx][ny] = nt
                    heapq.heappush(pq, (nt, nx, ny))
        return ans[n - 1][m - 1]