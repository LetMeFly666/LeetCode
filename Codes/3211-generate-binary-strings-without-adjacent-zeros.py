'''
Author: LetMeFly
Date: 2024-10-29 23:26:07
LastEditors: LetMeFly
LastEditTime: 2024-10-29 23:29:26
'''
from typing import List

class Solution:
    def validStrings(self, n: int) -> List[str]:
        ans = []
        mask = (1 << n) - 1
        for i in range(1 << n):
            x = i ^ mask
            if not x & (x >> 1):
                ans.append(f'{i:0{n}b}')
        return ans