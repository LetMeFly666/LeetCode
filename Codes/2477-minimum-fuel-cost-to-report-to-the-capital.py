'''
Author: LetMeFly
Date: 2023-12-05 19:52:52
LastEditors: LetMeFly
LastEditTime: 2023-12-05 19:57:04
'''
from typing import List

class Solution:
    def dfs(self, node: int) -> int:
        self.visited[node] = True
        cnt = 1
        for nextNode in self.graph[node]:
            if not self.visited[nextNode]:
                peopleFromThatNode = self.dfs(nextNode)
                cnt += peopleFromThatNode
                self.ans += (peopleFromThatNode + self.seats - 1) // self.seats
        return cnt
    
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        self.ans = 0
        self.graph = [[] for _ in range(len(roads) + 1)]
        for from_, to in roads:
            self.graph[from_].append(to)
            self.graph[to].append(from_)
        self.visited = [False] * (len(roads) + 1)
        self.seats = seats
        self.dfs(0)
        return self.ans