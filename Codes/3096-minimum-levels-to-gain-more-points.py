'''
Author: LetMeFly
Date: 2024-07-19 16:08:14
LastEditors: LetMeFly
LastEditTime: 2024-07-19 16:10:02
'''
from typing import List

class Solution:
    def minimumLevels(self, possible: List[int]) -> int:
        cnt = sum(1 if t == 1 else -1 for t in possible)
        now = 0
        for i in range(0, len(possible) - 1):
            now += 1 if possible[i] == 1 else -1
            if now > cnt - now:
                return i + 1
        return -1