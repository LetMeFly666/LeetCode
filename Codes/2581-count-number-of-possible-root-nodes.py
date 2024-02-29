'''
Author: LetMeFly
Date: 2024-02-29 14:33:08
LastEditors: LetMeFly
LastEditTime: 2024-02-29 14:43:07
'''
from typing import List

class Solution:  # AC,100.00%,92.59%
    def dfs(self, thisNode: int, lastNode: int) -> None:
        for nextNode in self.graph[thisNode]:
            if nextNode == lastNode:
                continue
            if (thisNode * 1000000 + nextNode) in self.se:
                self.cnt += 1
            self.dfs(nextNode, thisNode)
    
    def change(self, thisNode: int, lastNode: int, cnt: int) -> None:
        cnt_bak = cnt
        for nextNode in self.graph[thisNode]:
            if nextNode == lastNode:
                continue
            if (thisNode * 1000000 + nextNode) in self.se:
                cnt -= 1
            if (nextNode * 1000000 + thisNode) in self.se:
                cnt += 1
            self.ans += cnt >= self.k
            self.change(nextNode, thisNode, cnt)
            cnt = cnt_bak            

    def rootCount(self, edges: List[List[int]], guesses: List[List[int]], k: int) -> int:
        self.graph = [[] for _ in range(len(edges) + 1)]
        for x, y in edges:
            self.graph[x].append(y)
            self.graph[y].append(x)
        self.se = set()
        for x, y in guesses:
            self.se.add(x * 1000000 + y)
        self.cnt = 0
        self.dfs(0, -1)
        self.k = k
        self.ans = 1 if self.cnt >= k else 0
        self.change(0, -1, self.cnt)
        return self.ans
