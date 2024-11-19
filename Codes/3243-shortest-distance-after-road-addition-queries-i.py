'''
Author: LetMeFly
Date: 2024-11-19 14:37:55
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-19 14:45:39
'''
from typing import List

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        shortest = [i for i in range(n)]
        fromList = [[i - 1] for i in range(n)]
        ans = []
        for from_, to in queries:
            fromList[to].append(from_)
            for i in range(to, n):
                shortest[i] = min(shortest[i], min(shortest[j] + 1 for j in fromList[i]))
            ans.append(shortest[-1])
        return ans
