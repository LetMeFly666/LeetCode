'''
Author: LetMeFly
Date: 2026-07-01 17:16:47
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-03 10:50:51
'''
from typing import List
from collections import deque
import heapq

class Solution:
    def __init__(self) -> None:
        self.directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    
    def genDis(self, grid: List[List[int]]):
        n, m = len(grid), len(grid[0])
        dis = [[-1] * m for _ in range(n)]
        q = deque()
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v:
                    q.append((i, j))
                    dis[i][j] = 0
        
        while q:
            x, y = q.popleft()
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and dis[nx][ny] == -1:
                    q.append((nx, ny))
                    dis[nx][ny] = dis[x][y] + 1
        self.dis = dis

    def dfs(self) -> int:
        n, m = len(self.dis), len(self.dis[0])
        visited = [[False] * m for _ in range(n)]
        pq = [(-self.dis[0][0], 0, 0)]
        visited[0][0] = True
        ans = self.dis[0][0]
        if n == 1 and m == 1:
            return ans
        
        while pq:
            dis, x, y = heapq.heappop(pq)
            dis = -dis
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                    visited[nx][ny] = True
                    ans = min(ans, self.dis[nx][ny])
                    if nx == n - 1 and ny == m - 1:
                        return ans
                    heapq.heappush(pq, (-self.dis[nx][ny], nx, ny))

    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        self.genDis(grid)
        return self.dfs()
