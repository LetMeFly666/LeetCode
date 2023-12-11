'''
Author: LetMeFly
Date: 2023-12-11 17:33:10
LastEditors: LetMeFly
LastEditTime: 2023-12-11 19:25:22
'''
from typing import List
import heapq


directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n, m = len(heights), len(heights[0])
        graph = [[] for _ in range(n * m)]
        for i in range(n):
            for j in range(m):
                for di, dj in directions:
                    ti, tj = i + di, j + dj
                    if ti < 0 or ti >= n or tj < 0 or tj >= m:
                        continue
                    graph[i * m + j].append((ti * m + tj, abs(heights[ti][tj] - heights[i][j])))
        pq = [(0, 0)]
        ans = [1000000000] * (n * m)
        ans[0] = 0
        while pq:
            thisDiff, thisNode = heapq.heappop(pq)
            for toNode, toDiff in graph[thisNode]:
                newDiff = max(thisDiff, toDiff)
                if ans[toNode] > newDiff:
                    ans[toNode] = newDiff
                    heapq.heappush(pq, (newDiff, toNode))
                    # print(thisNode, toNode, newDiff)
        return ans[-1]
