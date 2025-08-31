'''
Author: LetMeFly
Date: 2025-08-28 12:54:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-31 19:11:00
'''
from typing import List

class Solution:
    directions = [
        [1, 1],
        [1, -1],
        [-1, -1],
        [-1, 1]
    ]

    """
    canContinue只考虑从(i, j)开始能否沿着方向d走一步
    """
    def canContinue(self, i: int, j: int, d: int) -> bool:
        ni, nj = i + self.directions[d][0], j + self.directions[d][1]
        if ni < 0 or ni >= self.n or nj < 0 or nj >= self.m:
            return False
        now = self.grid[i][j]
        next = self.grid[ni][nj]
        return now == 1 and next == 2 or now != 1 and next != 1 and now != next
    
    def getCacheKey(self, i: int, j: int, d: int, canChange: bool) -> int:
        return i * self.m * 8 + j * 8 + d * 2 + canChange

    def dfs(self, i: int, j: int, d: int, canChange: bool) -> int:
        cacheKey = self.getCacheKey(i, j, d, canChange)
        if self.cache[cacheKey] != -1:
            return self.cache[cacheKey]
        then = 0
        if self.canContinue(i, j, d):
            then = self.dfs(i + self.directions[d][0], j + self.directions[d][1], d, canChange)
        if canChange:
            nd = (d + 1) % 4
            if self.canContinue(i, j, nd):
                then = max(then, self.dfs(i + self.directions[nd][0], j + self.directions[nd][1], nd, False))
        self.cache[cacheKey] = then + 1
        return then + 1

    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.n, self.m = len(grid), len(grid[0])
        self.cache = [-1] * (self.m * self.n * 8)
        ans = 0
        for i, line in enumerate(grid):
            for j, g in enumerate(line):
                if g != 1:
                    continue
                for d in range(4):
                    ans = max(ans, self.dfs(i, j, d, True))
        return ans


if __name__ == '__main__':
    from functools import cache
    class A:
        def __init__(self, x):
            self.x = x

        @cache
        def f(self, y):
            print("running f...")
            return self.x + y


    a1 = A(10)
    a2 = A(20)

    print(a1.f(1))  # 运行函数，输出 11
    print(a1.f(1))  # 命中缓存，直接输出 11
    print(a2.f(1))  # 不命中缓存，输出21
