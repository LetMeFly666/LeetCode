'''
Author: LetMeFly
Date: 2025-02-20 11:06:38
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-20 11:08:51
'''
from typing import List

class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        ans = [0, 0]
        index = False
        while n:
            ans[index] += n & 1
            index = not index
            n >>= 1
        return ans