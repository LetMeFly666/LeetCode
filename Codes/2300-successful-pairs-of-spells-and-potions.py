'''
Author: LetMeFly
Date: 2023-11-10 14:25:21
LastEditors: LetMeFly
LastEditTime: 2023-11-10 14:28:30
'''
from typing import List
from bisect import bisect_left

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        for i in range(len(spells)):
            toFind = success // spells[i]
            if toFind * spells[i] < success:
                toFind += 1
            spells[i] = len(potions) - bisect_left(potions, toFind)
        return spells
