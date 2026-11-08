'''
Author: LetMeFly
Date: 2026-11-08 10:46:44
LastEditors: LetMeFly.xyz
LastEditTime: 2026-11-08 10:56:14
'''
class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        a, b = [0] * n, [0] * m
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v:
                    a[i] += 1
                    b[j] += 1
        
        ans = 0
        for i, row in enumerate(grid):
            for j, v in enumerate(row):
                if v and (a[i] > 1 or b[j] > 1):
                    ans += 1
        return ans
