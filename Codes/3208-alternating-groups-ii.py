'''
Author: LetMeFly
Date: 2024-11-28 23:30:30
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-28 23:33:29
'''
from typing import List

class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        ans = 0
        cntDiff = sum(colors[i] != colors[i - 1] for i in range(1, k))
        for i in range(len(colors)):
            ans += cntDiff == k - 1
            cntDiff += colors[(i + k) % len(colors)] != colors[(i + k - 1) % len(colors)]
            cntDiff -= colors[(i + 1) % len(colors)] != colors[i]
        return ans