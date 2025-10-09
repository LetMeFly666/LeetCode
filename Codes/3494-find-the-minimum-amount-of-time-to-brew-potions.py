'''
Author: LetMeFly
Date: 2025-10-09 22:52:05
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-09 23:07:02
'''
from typing import List

class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        times = [0] * len(skill)
        for m in mana:
            lastTime = times[0] + skill[0] * m
            for i in range(1, len(skill)):
                lastTime = max(lastTime, times[i]) + skill[i] * m
            times[-1] = lastTime
            for i in range(len(skill) - 2, -1, -1):
                times[i] = times[i + 1] - skill[i + 1] * m
        return times[-1]