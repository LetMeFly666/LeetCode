'''
Author: LetMeFly
Date: 2023-12-14 19:03:32
LastEditors: LetMeFly
LastEditTime: 2023-12-14 19:25:57
'''
from typing import List

class Solution:
    def possibleToStamp(self, grid: List[List[int]], h: int, w: int) -> bool:
        n, m = len(grid), len(grid[0])
        prefix = [[0] * (m + 1) for _ in range(n + 1)]
        diff = [[0] * (m + 2) for _ in range(n + 2)]
        # get-prefix
        for i in range(n):
            for j in range(m):
                prefix[i + 1][j + 1] = grid[i][j] + prefix[i + 1][j] + prefix[i][j + 1] - prefix[i][j]
        # stamp
        for i in range(n - h + 1):
            for j in range(m - w + 1):
                # (i, j) -> (i + h - 1, j + w - 1)
                if not grid[i][j] and not (prefix[i + h][j + w] + prefix[i][j] - prefix[i + h][j] - prefix[i][j + w]):
                    diff[i + 1][j + 1] += 1
                    diff[i + h + 1][j + 1] -= 1
                    diff[i + 1][j + w + 1] -= 1
                    diff[i + h + 1][j + w + 1] += 1
        # un-diff
        for i in range(n):
            for j in range(m):
                diff[i + 1][j + 1] += diff[i + 1][j] + diff[i][j + 1] - diff[i][j]
                if not grid[i][j] and not diff[i + 1][j + 1]:
                    return False
        return True