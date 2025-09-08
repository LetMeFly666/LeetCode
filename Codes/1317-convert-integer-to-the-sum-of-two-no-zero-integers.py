'''
Author: LetMeFly
Date: 2025-09-08 23:05:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-08 23:13:48
'''
from typing import List

class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(n):
            if '0' not in str(i) and '0' not in str(n - i):
                return [i, n - i]
        return []  # FAKE RETURN