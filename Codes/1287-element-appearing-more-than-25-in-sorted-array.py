'''
Author: LetMeFly
Date: 2025-02-17 14:38:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-17 14:43:22
'''
from typing import List

class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        locDiff = len(arr) // 4
        for i in range(len(arr)):
            if arr[i] == arr[i + locDiff]:
                return arr[i]
        return -1  # Fake Return