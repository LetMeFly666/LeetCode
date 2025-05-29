'''
Author: LetMeFly
Date: 2025-05-29 22:14:08
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-29 23:40:08
'''
from typing import List, Tuple

class Solution:
    def edges2tree(self, edges: List[List[int]]) -> List[List[int]]:
        ans = [[] for _ in range(len(edges) + 1)]
        for x, y in edges:
            ans[x].append(y)
            ans[y].append(x)
        return ans
    
    def tree2color(self, tree: List[List[int]]) -> List[bool]:
        ans = [False] * len(tree)
        q = [(-1, 0, True)]
        while q:
            lastNode, thisNode, color = q[-1]
            q = q[:-1]
            ans[thisNode] = color
            for nextNode in tree[thisNode]:
                if nextNode != lastNode:
                    q.append((thisNode, nextNode, False if color else True))
        return ans
    
    def count01(self, color: List[bool]) -> Tuple[int, int]:
        ans = [0, 0]
        for c in color:
            ans[c] += 1
        return (*ans, )
    
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        graph1, graph2 = self.edges2tree(edges1), self.edges2tree(edges2)
        color1, color2 = self.tree2color(graph1), self.tree2color(graph2)
        toAdd = max(self.count01(color2))
        black1, white1 = self.count01(color1)
        black1, white1 = black1 + toAdd, white1 + toAdd
        return [white1 if c else black1 for c in color1]