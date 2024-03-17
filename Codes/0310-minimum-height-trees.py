'''
Author: LetMeFly
Date: 2024-03-17 20:55:15
LastEditors: LetMeFly
LastEditTime: 2024-03-17 20:58:11
'''
from typing import List

class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        degree = [0] * n
        graph = [[] for _ in range(n)]
        for x, y in edges:
            degree[x] += 1
            degree[y] += 1
            graph[x].append(y)
            graph[y].append(x)
        q = [i for i, d in enumerate(degree) if d == 1]
        remainNode = n
        while remainNode > 2:
            tempQ = []
            for thisNode in q:
                remainNode -= 1
                for nextNode in graph[thisNode]:
                    degree[nextNode] -= 1
                    if degree[nextNode] == 1:
                        tempQ.append(nextNode)
            q = tempQ
        return q
