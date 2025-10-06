'''
Author: LetMeFly
Date: 2025-10-06 12:17:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-06 13:06:15
'''
from typing import List
import heapq

class Solution:
    directions = [[0, 1], [0, -1], [-1, 0], [1, 0]]

    def swimInWater(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        if n == 1 and m == 1:
            return grid[0][0]
        visited = [[False] * m for _ in range(n)]
        pq = [(grid[0][0], 0, 0)]
        visited[0][0] = True
        while True:
            val, x, y = heapq.heappop(pq)
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if (not (0 <= nx < n and 0 <= ny < m)) or visited[nx][ny]:
                    continue
                grid[nx][ny] = max(grid[nx][ny], val)
                if nx == n - 1 and ny == m - 1:
                    return grid[nx][ny]
                visited[nx][ny] = True
                heapq.heappush(pq, (grid[nx][ny], nx, ny))
