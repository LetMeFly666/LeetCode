'''
Author: LetMeFly
Date: 2026-09-19 08:23:49
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-19 08:43:25
'''
class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        x = max(x1, min(xCenter, x2))
        y = max(y1, min(yCenter, y2))
        return (x - xCenter) ** 2 + (y - yCenter) ** 2 <= radius ** 2
