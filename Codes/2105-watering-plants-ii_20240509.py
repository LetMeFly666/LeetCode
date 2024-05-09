'''
Author: LetMeFly
Date: 2024-05-09 15:38:14
LastEditors: LetMeFly
LastEditTime: 2024-05-09 15:41:06
'''
from typing import List


class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        ans = 0
        nowA, nowB = capacityA, capacityB
        l, r = 0, len(plants) - 1
        while l <= r:
            if l == r:
                if max(nowA, nowB) < plants[l]:
                    ans += 1
                break
            if nowA < plants[l]:
                ans += 1
                nowA = capacityA
            nowA -= plants[l]
            if nowB < plants[r]:
                ans += 1
                nowB = capacityB
            nowB -= plants[r]
            l += 1
            r -= 1
        return ans