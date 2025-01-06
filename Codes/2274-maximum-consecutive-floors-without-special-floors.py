'''
Author: LetMeFly
Date: 2025-01-06 20:36:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-06 20:38:18
'''
from typing import List

class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.sort()
        ans = max(special[0] - bottom, top - special[-1])
        for i in range(1, len(special)):
            ans = max(ans, special[i] - special[i - 1] - 1)
        return ans