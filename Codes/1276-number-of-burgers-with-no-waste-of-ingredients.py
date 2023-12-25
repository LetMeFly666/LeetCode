'''
Author: LetMeFly
Date: 2023-12-25 12:19:03
LastEditors: LetMeFly
LastEditTime: 2023-12-25 12:20:54
'''
from typing import List

class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        x, y = int(0.5 * tomatoSlices - cheeseSlices), int(2 * cheeseSlices - 0.5 * tomatoSlices)
        if x < 0 or y < 0 or 4 * x + 2 * y != tomatoSlices:
            return []
        return [x, y]
