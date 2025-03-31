'''
Author: LetMeFly
Date: 2025-03-31 14:33:18
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-31 14:34:50
'''
from typing import List

class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        ans = []
        j = 0
        for i, c in enumerate(s):
            if j < len(spaces) and spaces[j] == i:
                ans.append(' ')
                j += 1
            ans.append(c)
        return ''.join(ans)