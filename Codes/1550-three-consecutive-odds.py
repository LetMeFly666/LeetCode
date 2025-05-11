'''
Author: LetMeFly
Date: 2025-05-11 14:00:52
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-11 14:16:01
Description: AC,100.00%,93.48%
'''
from typing import List

class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        for i in range(2, len(arr)):
            if arr[i] % 2 and arr[i - 1] % 2 and arr[i - 2] % 2:
                return True
        return False