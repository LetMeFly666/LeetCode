'''
Author: LetMeFly
Date: 2024-11-20 12:46:44
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-20 12:54:50
'''
from typing import List

class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        transitionTo = [i + 1 for i in range(n)]
        ans = []
        shortestTimes = n - 1
        for from_, to in queries:
            while transitionTo[from_] < to:
                shortestTimes -= 1
                transitionTo[from_], from_ = to, transitionTo[from_]
            ans.append(shortestTimes)
        return ans