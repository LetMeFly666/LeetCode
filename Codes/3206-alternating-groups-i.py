'''
Author: LetMeFly
Date: 2024-11-26 23:20:18
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-26 23:20:28
'''
from typing import List

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        return sum(colors[i] != colors[(i + 1) % len(colors)] != colors[(i + 2) % len(colors)] for i in range(len(colors)))