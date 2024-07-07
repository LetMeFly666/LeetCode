'''
Author: LetMeFly
Date: 2024-07-07 17:00:53
LastEditors: LetMeFly
LastEditTime: 2024-07-07 17:05:23
'''
from typing import List

DIRECTIONS = [[0, 1], [0, -1], [1, 0], [-1, 0], [1, 1], [1, -1], [-1, 1], [-1, -1]]

class Solution:
    def inBoard(self, x: int, y: int) -> bool:
        return 0 <= x < 8 and 0 <= y < 8
    
    def checkMove(self, board: List[List[str]], rMove: int, cMove: int, color: str) -> bool:
        board[rMove][cMove] = color  # 其实不真的修改也没问题
        for tx, ty in DIRECTIONS:
            x, y = rMove + tx, cMove + ty
            if not self.inBoard(x, y):
                continue
            if board[x][y] == color or board[x][y] == '.':
                continue
            while self.inBoard(x + tx, y + ty):
                x, y = x + tx, y + ty
                if board[x][y] == color:
                    return True
                if board[x][y] == '.':
                    break
        return False
