'''
Author: LetMeFly
Date: 2024-04-04 15:23:07
LastEditors: LetMeFly
LastEditTime: 2024-04-04 15:27:57
'''
from typing import List
from collections import deque


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        father = [set() for _ in range(n)]
        degree = [0] * n
        graph = [[] for _ in range(n)]
        for x, y in edges:
            degree[y] += 1
            graph[x].append(y)
        q = deque()
        for i in range(n):
            if not degree[i]:
                q.append(i)
        while q:
            thisNode = q.popleft()
            for nextNode in graph[thisNode]:
                father[nextNode].add(thisNode)
                father[nextNode].update(father[thisNode])
                degree[nextNode] -= 1
                if not degree[nextNode]:
                    q.append(nextNode)
        return [sorted(list(i)) for i in father]
