'''
Author: LetMeFly
Date: 2023-10-21 15:47:28
LastEditors: LetMeFly
LastEditTime: 2023-10-21 16:00:06
'''
from typing import List

class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        visited = [False] * n
        sizes = []
        for i in range(n):
            if visited[i]:
                continue
            cntNode = 0
            visited[i] = True
            q = [i]
            while q:
                thisNode = q.pop()
                cntNode += 1
                for t in graph[thisNode]:
                    if not visited[t]:
                        visited[t] = True
                        q.append(t)
            sizes.append(cntNode)
        ans = 0
        for t in sizes:
            ans += t * (n - t)
        return ans // 2
