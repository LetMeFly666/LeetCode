'''
Author: LetMeFly
Date: 2024-10-24 12:21:28
LastEditors: LetMeFly
LastEditTime: 2024-10-24 12:23:00
'''
from typing import List

class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        maxLoc, curLoc, cnt = 0, 1, 0
        while curLoc < len(skills) and cnt < k:
            if skills[maxLoc] > skills[curLoc]:
                cnt += 1
            else:
                maxLoc = curLoc
                cnt = 1
            curLoc += 1
        return maxLoc