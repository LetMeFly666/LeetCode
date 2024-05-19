'''
Author: LetMeFly
Date: 2024-05-19 11:09:15
LastEditors: LetMeFly
LastEditTime: 2024-05-19 11:11:10
'''
from typing import List

class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        winner, winTime = arr[0], 0
        for i in range(1, len(arr)):
            if winner > arr[i]:
                winTime += 1
            else:
                winner = arr[i]
                winTime = 1
            if winTime == k:
                return winner
        return winner