'''
Author: LetMeFly
Date: 2024-04-13 09:32:38
LastEditors: LetMeFly
LastEditTime: 2024-04-13 09:34:06
'''
from typing import List

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        indegree = [0] * n
        for x, y in edges:
            indegree[y] += 1
        cntWinner, winner = 0, 0
        for i in range(n):
            if not indegree[i]:
                cntWinner += 1
                winner = i
        return winner if cntWinner == 1 else -1