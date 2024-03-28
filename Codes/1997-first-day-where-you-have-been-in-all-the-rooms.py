'''
Author: LetMeFly
Date: 2024-03-28 12:08:49
LastEditors: LetMeFly
LastEditTime: 2024-03-28 12:12:00
'''
from typing import List

class Solution:
    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
        firstVisit = [0] * len(nextVisit)
        for i in range(1, len(nextVisit)):
            firstVisit[i] = (firstVisit[i - 1] * 2 - firstVisit[nextVisit[i - 1]] + 2 + 1_000_000_007) % 1_000_000_007
        return firstVisit[-1]
