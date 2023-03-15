'''
Author: LetMeFly
Date: 2023-03-15 09:48:52
LastEditors: LetMeFly
LastEditTime: 2023-03-15 09:58:22
'''
from typing import List

class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        ans = 0
        cnt = [0 for _ in range(n)]
        se = set()
        for road in roads:
            cnt[road[0]] += 1
            cnt[road[1]] += 1
            se.add((road[0], road[1]))
            se.add((road[1], road[0]))
        for i in range(n):
            for j in range(i + 1, n):
                ans = max(ans, cnt[i] + cnt[j] - ((i, j) in se))
        return ans