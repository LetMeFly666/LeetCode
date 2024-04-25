'''
Author: LetMeFly
Date: 2024-04-25 09:39:30
LastEditors: LetMeFly
LastEditTime: 2024-04-25 09:41:03
'''
class Solution:
    def distanceTraveled(self, mainTank: int, additionalTank: int) -> int:
        added = min(additionalTank, (mainTank - 1) // 4)
        return added * 50 + (mainTank - added * 4) * 10