'''
Author: LetMeFly
Date: 2024-11-21 23:04:02
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-21 23:04:09
'''
from typing import List

class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        ans = 0
        for c in commands:
            if c[0] == 'U':
                ans -= n
            elif c[0] == 'D':
                ans += n
            elif c[0] == 'L':
                ans -= 1
            else:
                ans += 1
        return ans