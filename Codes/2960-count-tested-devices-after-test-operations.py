'''
Author: LetMeFly
Date: 2024-05-10 16:13:24
LastEditors: LetMeFly
LastEditTime: 2024-05-10 16:13:46
'''
from typing import List

class Solution:
    def countTestedDevices(self, batteryPercentages: List[int]) -> int:
        ans = 0
        for t in batteryPercentages:
            if t > ans:
                ans += 1
        return ans