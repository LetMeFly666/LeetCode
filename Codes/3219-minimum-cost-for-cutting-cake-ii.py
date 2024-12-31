'''
Author: LetMeFly
Date: 2024-12-31 13:10:50
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-31 13:14:10
'''
from typing import List

class Solution:
    def minimumCost(self, m: int, n: int, horizontalCut: List[int], verticalCut: List[int]) -> int:
        horizontalCut.sort(key=lambda a: -a)
        verticalCut.sort(key=lambda a: -a)
        ans = hCutTime = vCutTime = 0
        m, n = m - 1, n - 1
        while hCutTime < m or vCutTime < n:
            if vCutTime == n or hCutTime < m and horizontalCut[hCutTime] > verticalCut[vCutTime]:
                ans += horizontalCut[hCutTime] * (vCutTime + 1)
                hCutTime += 1
            else:
                ans += verticalCut[vCutTime] * (hCutTime + 1)
                vCutTime += 1
        return ans