'''
Author: LetMeFly
Date: 2023-04-11 10:38:40
LastEditors: LetMeFly
LastEditTime: 2023-04-11 10:57:56
'''
directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        nowDirection = 0
        x, y = 0, 0
        for c in instructions:
            if c == 'G':
                x += directions[nowDirection][0]
                y += directions[nowDirection][1]
            elif c == 'L':
                nowDirection = (nowDirection + 3) % 4
            else:
                nowDirection = (nowDirection + 1) % 4
        return nowDirection or (not x and not y)