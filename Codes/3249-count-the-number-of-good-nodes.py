'''
Author: LetMeFly
Date: 2024-11-14 12:56:25
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-14 13:00:23
'''
from typing import List

class Solution:
    def dfs(self, thisNode: int, parentNode: int=-1) -> int:
        cnt, oneChild, ok = 1, 0, True
        for nextNode in self.graph[thisNode]:
            if nextNode == parentNode:
                continue
            nextChild = self.dfs(nextNode, thisNode)
            cnt += nextChild
            if not oneChild:
                oneChild = nextChild
            elif oneChild != nextChild:
                ok = False
        if ok:
            self.ans += 1
        return cnt
    
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        self.graph = [[] for _ in range(len(edges) + 1)]
        for x, y in edges:
            self.graph[x].append(y)
            self.graph[y].append(x)
        self.ans = 0
        self.dfs(0)
        return self.ans