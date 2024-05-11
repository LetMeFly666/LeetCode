'''
Author: LetMeFly
Date: 2024-05-11 09:45:04
LastEditors: LetMeFly
LastEditTime: 2024-05-11 09:50:16
'''
from typing import List

class Solution:
    def garbageCollection(self, garbage: List[str], travel: List[int]) -> int:
        ans = 0
        last = [0] * 3
        collect = 'MPG'
        for i in range(len(garbage)):
            ans += len(garbage[i])
            for c in garbage[i]:
                for j in range(3):
                    if c == collect[j]:
                        last[j] = i
        for i in range(len(travel)):
            for j in range(3):
                if last[j] >= i + 1:
                    ans += travel[i]
        return ans
