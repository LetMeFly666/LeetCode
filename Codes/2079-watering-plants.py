'''
Author: LetMeFly
Date: 2024-05-08 18:10:56
LastEditors: LetMeFly
LastEditTime: 2024-05-08 18:12:06
'''
from typing import List

class Solution:
    def wateringPlants(self, plants: List[int], capacity: int) -> int:
        step = 0
        now = capacity
        for i in range(len(plants)):
            if now < plants[i]:
                step += i + i
                now = capacity
            step += 1
            now -= plants[i]
        return step