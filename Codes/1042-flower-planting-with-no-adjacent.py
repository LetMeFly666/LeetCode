'''
Author: LetMeFly
Date: 2023-04-15 12:09:18
LastEditors: LetMeFly
LastEditTime: 2023-04-15 12:20:17
'''
from typing import List

class Solution:
    def gardenNoAdj(self, n: int, paths: List[List[int]]) -> List[int]:
        ans = [0] * n
        graph = [[] for _ in range(n)]
        for path in paths:
            graph[path[0] - 1].append(path[1] - 1)
            graph[path[1] - 1].append(path[0] - 1)
        for i in range(n):
            visited = [False] * 5
            for toPoint in graph[i]:
                visited[ans[toPoint]] = True
            for j in range(1, 5):
                if not visited[j]:
                    ans[i] = j
                    break
        return ans