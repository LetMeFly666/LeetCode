'''
Author: LetMeFly
Date: 2023-11-10 12:58:45
LastEditors: LetMeFly
LastEditTime: 2023-11-10 13:39:26
'''
from typing import List
from copy import deepcopy

class Solution:
    def __init__(self) -> None:
        self.direction = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    
    def bfsFire(self, grid: List[List[int]]) -> None:
        fireTime = [[int(1e9)] * self.n for _ in range(self.m)]
        graph = deepcopy(grid)
        q = []
        for i in range(self.m):
            for j in range(self.n):
                if graph[i][j] == 1:
                    q.append((i, j))
                    fireTime[i][j] = 0
        while q:
            x, y = q[0]
            q = q[1:]
            for dx, dy in self.direction:
                tx, ty = x + dx, y + dy
                if tx >= 0 and tx < self.m and ty >= 0 and ty < self.n and not graph[tx][ty]:
                    q.append((tx, ty))
                    fireTime[tx][ty] = fireTime[x][y] + 1
                    graph[tx][ty] = 1
        self.fireTime = fireTime
    
    def check(self, grid: List[List[int]], t: int) -> bool:
        if t == 4:
            print(self.fireTime)
        peopleTime = [[0] * self.n for _ in range(self.m)]
        graph = deepcopy(grid)
        q = []
        q.append((0, 0))
        graph[0][0] = 2
        peopleTime[0][0] = t
        while q:
            x, y = q[0]
            q = q[1:]
            thisTime = peopleTime[x][y] + 1
            for dx, dy in self.direction:
                tx, ty = x + dx, y + dy
                if tx >= 0 and tx < self.m and ty >= 0 and ty < self.n and not graph[tx][ty]:
                    graph[tx][ty] = 2
                    if tx == self.m - 1 and ty == self.n - 1 and thisTime <= self.fireTime[-1][-1]:
                        return True
                    if thisTime < self.fireTime[tx][ty]:
                        peopleTime[tx][ty] = thisTime
                        q.append((tx, ty))
        return False

    def maximumMinutes(self, grid: List[List[int]]) -> int:
        self.m, self.n = len(grid), len(grid[0])
        self.bfsFire(grid)
        l, r = 0, self.m * self.n
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if self.check(grid, mid):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return int(1e9) if ans >= self.m * self.n else ans

if __name__ == '__main__':
    print(Solution().maximumMinutes(
        [[0,2,0,0,0,0,0],
         [0,0,0,2,2,1,0],
         [0,2,0,0,1,2,0],
         [0,0,2,2,2,0,2],
         [0,0,0,0,0,0,0]])
    )
    """
    [[6, ∞, 4, 3, 2, 1, 2],
     [5, 4, 3, ∞, ∞, 0, 1],
     [6, ∞, 2, 1, 0, ∞, 2],
     [7, 8, ∞, ∞, ∞, 14, ∞],
     [8, 9, 10, 11, 12, 13, 14]]
    """