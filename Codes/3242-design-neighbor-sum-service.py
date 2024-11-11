'''
Author: LetMeFly
Date: 2024-11-09 10:07:15
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-09 10:15:02
'''
from typing import List

direction = [[-1, 0], [1, 0], [0, -1], [0, 1], [-1, -1], [1, 1], [-1, 1], [1, -1]]

class NeighborSum:
    def __init__(self, grid: List[List[int]]):
        n = len(grid)
        self.cache = [[0, 0] for _ in range(n * n)]
        for i in range(n):
            for j in range(n):
                for th, (x, y) in enumerate(direction):
                    if 0 <= x + i < n and 0 <= y + j < n:
                        self.cache[grid[i][j]][th // 4] += grid[x + i][y + j]

    def adjacentSum(self, value: int) -> int:
        return self.cache[value][0]

    def diagonalSum(self, value: int) -> int:
        return self.cache[value][1]


# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)