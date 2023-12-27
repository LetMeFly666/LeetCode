'''
Author: LetMeFly
Date: 2023-12-27 15:13:18
LastEditors: LetMeFly
LastEditTime: 2023-12-27 15:15:38
'''
from typing import List

class Solution:
    def getScore(self, v: List[int]) -> int:
        if len(v) == 1:
            return v[0]
        ans = v[0] + (2 if v[0] == 10 else 1) * v[1]
        for i in range(2, len(v)):
            ans += (2 if v[i - 1] == 10 or v[i - 2] == 10 else 1) * v[i]
        return ans
    
    def isWinner(self, player1: List[int], player2: List[int]) -> int:
        v1, v2 = self.getScore(player1), self.getScore(player2)
        return 0 if v1 == v2 else 2 if v1 < v2 else 1