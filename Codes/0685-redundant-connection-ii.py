'''
Author: LetMeFly
Date: 2024-11-03 16:52:35
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-03 17:01:19
'''
from typing import List

class Solution:
    def initFa(self) -> None:
        for i in range(1, len(self.edges) + 1):
            self.fa[i] = i
    
    def find(self, x: int) -> int:
        if self.fa[x] != x:
            self.fa[x] = self.find(self.fa[x])
        return self.fa[x]
    
    def union(self, x: int, y: int) -> None:
        self.fa[self.find(x)] = self.find(y)
    
    def couldRemoveThisEdge(self, index: int) -> bool:
        self.initFa()
        for i in range(len(self.edges)):
            if i == index:
                continue
            if self.find(self.edges[i][0]) == self.find(self.edges[i][1]):
                return False
            else:
                self.union(self.edges[i][0], self.edges[i][1])
        return True

    def solution_indegree(self, node: int) -> List[int]:
        for i in range(len(self.edges) - 1, -1, -1):
            if self.edges[i][1] == node and self.couldRemoveThisEdge(i):
                return self.edges[i]
        return []  # FAKE RETURN

    def solution_unionFind(self) -> List[int]:
        self.initFa()
        for x, y in self.edges:
            if self.find(x) == self.find(y):
                return [x, y]
            else:
                self.union(x, y)
        return []  # FAKE RETURN
    
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        self.fa = [0] * (len(edges) + 1)
        self.edges = edges
        hasIndegree = [False] * (len(edges) + 1)
        for x, y in edges:
            if hasIndegree[y]:
                return self.solution_indegree(y)
            else:
                hasIndegree[y] = True
        return self.solution_unionFind()