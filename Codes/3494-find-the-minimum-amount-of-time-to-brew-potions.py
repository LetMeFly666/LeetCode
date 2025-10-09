'''
Author: LetMeFly
Date: 2025-10-09 22:52:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-09 23:11:26
'''
from typing import List

class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n = len(skill)
        times = [0] * n
        for m in mana:
            lastTime = times[0] + skill[0] * m
            for i in range(1, n):
                lastTime = max(lastTime, times[i]) + skill[i] * m
            times[-1] = lastTime
            for i in range(n - 2, -1, -1):
                times[i] = times[i + 1] - skill[i + 1] * m
        return times[-1]