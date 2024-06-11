'''
Author: LetMeFly
Date: 2024-06-11 12:20:29
LastEditors: LetMeFly
LastEditTime: 2024-06-11 12:21:50
'''
from typing import List

class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        return sum(board[i][j] == 'X' and (i == 0 or board[i - 1][j] == '.') and (j == 0 or board[i][j - 1] == '.') for j in range(len(board[0])) for i in range(len(board)))