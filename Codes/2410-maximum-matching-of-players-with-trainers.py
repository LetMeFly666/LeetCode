'''
Author: LetMeFly
Date: 2025-07-13 16:44:48
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-13 17:00:27
'''
from typing import List

class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        ans = p = t = 0
        while t < len(trainers) and p < len(players):
            if trainers[t] >= players[p]:
                ans += 1
                p += 1
            t += 1
        return ans