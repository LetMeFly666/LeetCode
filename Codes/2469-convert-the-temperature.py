'''
Author: LetMeFly
Date: 2023-03-21 12:24:09
LastEditors: LetMeFly
LastEditTime: 2023-03-21 12:25:15
'''
from typing import List


class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        return [celsius + 273.15, celsius * 1.8 + 32]