'''
Author: LetMeFly
Date: 2025-09-04 13:33:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-04 13:37:22
'''
class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        diff = abs(x - z) - abs(y - z)
        return 2 if diff > 0 else 1 if diff else 0