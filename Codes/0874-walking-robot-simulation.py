'''
Author: LetMeFly
Date: 2023-07-19 08:46:21
LastEditors: LetMeFly
LastEditTime: 2023-07-19 09:00:18
'''
from typing import List

directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]  # ↑→↓←

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        se = set()
        for obstacle in obstacles:
            se.add(tuple(obstacle))
        
        x, y, nowDirection = 0, 0, 0
        ans = 0
        for command in commands:
            if command == -2:
                nowDirection = (nowDirection + 3) % 4
            elif command == -1:
                nowDirection = (nowDirection + 1) % 4
            else:
                for i in range(command):
                    tx, ty = x + directions[nowDirection][0], y + directions[nowDirection][1]
                    if (tx, ty) in se:
                        break
                    x, y = tx, ty
                    ans = max(ans, x * x + y * y)
        return ans
