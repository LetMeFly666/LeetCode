'''
Author: LetMeFly
Date: 2024-06-04 21:47:07
LastEditors: LetMeFly
LastEditTime: 2024-06-04 21:54:22
'''
from typing import List

class Solution:
    def dfs(self, from_: int, to: int, cntDistance: int) -> int:
        ans = 0 if cntDistance % self.signalSpeed else 1
        for nextNode, nextDistance in self.graph[to]:
            if nextNode == from_:
                continue
            ans += self.dfs(to, nextNode, cntDistance + nextDistance)
        return ans

    def countPairsOfConnectableServers(self, edges: List[List[int]], signalSpeed: int) -> List[int]:
        # init
        self.signalSpeed = signalSpeed
        graph = [[] for _ in range(len(edges) + 1)]
        for x, y, d in edges:
            graph[x].append((y, d))
            graph[y].append((x, d))
        self.graph = graph
        # calculate
        ans = [0] * (len(edges) + 1)
        for c in range(len(ans)):
            ab = []
            for to, distance in graph[c]:
                ab.append(self.dfs(c, to, distance))
            for i in range(len(ab)):
                for j in range(i + 1, len(ab)):
                    ans[c] += ab[i] * ab[j]
        return ans
