'''
Author: LetMeFly
Date: 2024-07-01 14:33:49
LastEditors: LetMeFly
LastEditTime: 2024-07-01 14:41:24
'''
from typing import List

class Solution:
    def dfs(self, root, time, value) -> None:
        if not root:
            self.ans = max(self.ans, value)
        for next, distance in self.graph[root]:
            if time + distance > self.maxTime:
                continue
            if self.visited[next]:
                self.dfs(next, time + distance, value)
            else:
                self.visited[next] = True
                self.dfs(next, time + distance, value + self.values[next])
                self.visited[next] = False
    
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        self.ans = 0
        self.maxTime = maxTime
        self.values = values
        self.graph = [[] for _ in range(len(values))]
        for x, y, d in edges:
            self.graph[x].append((y, d))
            self.graph[y].append((x, d))
        self.visited = [False] * len(values)
        self.visited[0] = True
        self.dfs(0, 0, values[0])
        return self.ans