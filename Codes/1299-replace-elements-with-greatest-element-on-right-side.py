'''
Author: LetMeFly
Date: 2025-02-16 10:21:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-16 10:23:15
'''
from typing import List

class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        M = -1
        for i in range(len(arr) - 1, -1, -1):
            arr[i], M = M, max(arr[i], M)
        return arr