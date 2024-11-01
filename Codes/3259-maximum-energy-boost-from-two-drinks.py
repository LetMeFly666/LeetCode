'''
Author: LetMeFly
Date: 2024-11-01 12:32:07
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-01 12:33:35
'''
from typing import List

class Solution:
    def maxEnergyBoost(self, energyDrinkA: List[int], energyDrinkB: List[int]) -> int:
        day0a, day0b, day1a, day1b = 0, 0, energyDrinkA[0], energyDrinkB[0]
        for i in range(1, len(energyDrinkA)):
            day0a, day0b, day1a, day1b = day1a, day1b, max(day1a, day0b) + energyDrinkA[i], max(day0a, day1b) + energyDrinkB[i]
        return max(day1a, day1b)