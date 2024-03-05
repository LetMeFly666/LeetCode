'''
Author: LetMeFly
Date: 2024-03-05 14:54:57
LastEditors: LetMeFly
LastEditTime: 2024-03-05 15:03:10
'''
from typing import List
import heapq

MOD = int(1e9) + 7

class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for x, y, d in roads:
            graph[x].append((y, d))
            graph[y].append((x, d))
        way = [0] * n
        way[0] = 1
        dis = [int(1e18)] * n
        dis[0] = 0
        pq = [(0, 0)]
        while pq:
            thisDistance, thisNode = heapq.heappop(pq)
            if thisDistance > dis[thisNode]:
                continue
            for nextNode, nextDistance in graph[thisNode]:
                if nextDistance + thisDistance < dis[nextNode]:
                    dis[nextNode] = nextDistance + thisDistance
                    way[nextNode] = way[thisNode]
                    heapq.heappush(pq, (dis[nextNode], nextNode))
                elif nextDistance + thisDistance == dis[nextNode]:
                    way[nextNode] = (way[nextNode] + way[thisNode]) % MOD
        return way[-1]
