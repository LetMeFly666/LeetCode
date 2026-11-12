'''
Author: LetMeFly
Date: 2026-11-12 19:11:20
LastEditors: LetMeFly.xyz
LastEditTime: 2026-11-12 19:13:36
'''
from typing import List

class ABC:
    def __init__(self) -> None:
        self.a = [0, 0, 0]
        self.diff = 0
    
    def push(self, v: int):
        self.a[self.diff] = v
        self.diff = (self.diff + 1) % 3
    
    def __getitem__(self, i: int) -> int:
        return self.a[i]

class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        abc = ABC()
        for cost in costs:
            abc.push(cost + min(
                abc[0] + 9,
                abc[1] + 4,
                abc[2] + 1
            ))
        return abc[2]
