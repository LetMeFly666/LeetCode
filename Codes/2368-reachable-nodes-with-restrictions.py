'''
Author: LetMeFly
Date: 2024-03-02 16:19:02
LastEditors: LetMeFly
LastEditTime: 2024-03-02 16:21:41
'''
from typing import List

class Solution:
    def dfs(self, n: int) -> None:
        self.unachieveable.add(n)
        self.ans += 1
        for next in self.graph[n]:
            if next not in self.unachieveable:
                self.dfs(next)
    
    def reachableNodes(self, n: int, edges: List[List[int]], restricted: List[int]) -> int:
        self.ans = 0
        self.graph = [[] for _ in range(n)]
        for x, y in edges:
            self.graph[x].append(y)
            self.graph[y].append(x)
        self.unachieveable = set(restricted)
        self.dfs(0)
        return self.ans
