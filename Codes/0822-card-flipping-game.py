'''
Author: LetMeFly
Date: 2023-08-02 07:56:59
LastEditors: LetMeFly
LastEditTime: 2023-08-02 07:58:12
'''
from typing import List

class Solution:
    def flipgame(self, fronts: List[int], backs: List[int]) -> int:
        se = set()
        n = len(fronts)
        for i in range(n):
            if fronts[i] == backs[i]:
                se.add(fronts[i])
        ans = 2001
        for i in range(n):
            for value in (fronts[i], backs[i]):
                if value not in se:
                    ans = min(ans, value)
        return 0 if ans == 2001 else ans