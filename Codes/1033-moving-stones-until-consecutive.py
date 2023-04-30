'''
Author: LetMeFly
Date: 2023-04-30 09:53:59
LastEditors: LetMeFly
LastEditTime: 2023-04-30 10:14:25
'''
from typing import List

class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        if a + 1 == b and b + 1 == c:
            return [0, 0]
        elif a + 1 == b or b + 1 == c or a + 2 == b or b + 2 == c:
            return [1, c - a - 2]
        else:
            return [2, c - a - 2]