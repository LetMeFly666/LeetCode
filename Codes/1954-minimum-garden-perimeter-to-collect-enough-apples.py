'''
Author: LetMeFly
Date: 2023-12-24 16:38:35
LastEditors: LetMeFly
LastEditTime: 2023-12-24 16:39:55
'''
from numpy import cbrt

class Solution:
    def minimumPerimeter(self, neededApples: int) -> int:
        ans = int(cbrt(0.25 * neededApples))
        while 2 * ans * (ans + 1) * (2 * ans + 1) < neededApples:
            ans += 1
        return ans * 8