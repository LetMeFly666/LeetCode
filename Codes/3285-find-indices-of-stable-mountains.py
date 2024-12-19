'''
Author: LetMeFly
Date: 2024-12-19 15:58:23
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-19 16:11:17
'''
from typing import List

class Solution:
    def stableMountains(self, height: List[int], threshold: int) -> List[int]:
        return [i for i in range(1, len(height)) if height[i - 1] > threshold]