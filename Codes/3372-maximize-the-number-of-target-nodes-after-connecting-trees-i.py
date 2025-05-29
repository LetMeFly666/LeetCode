'''
Author: LetMeFly
Date: 2025-05-28 21:43:27
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-28 23:05:02
'''
from typing import List

class Solution:
    def buildTree(self, edges: List[List[int]]) -> List[List[int]]:
        ans = [[] for _ in range(len(edges) + 1)]
        for x, y in edges:
            ans[x].append(y)
            ans[y].append(x)
        return ans
    
    def dfs(self, tree: List[List[int]], lastNode: int, thisNode: int, k: int) -> int:
        if k < 0:
            return 0
        ans = 1
        for nextNode in tree[thisNode]:
            if nextNode != lastNode:
                ans += self.dfs(tree, thisNode, nextNode, k - 1)
        return ans
    
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        tree2 = self.buildTree(edges2)
        toAdd = max(self.dfs(tree2, -1, i, k - 1) for i in range(len(tree2)))
        tree1 = self.buildTree(edges1)
        return [self.dfs(tree1, -1, i, k) + toAdd for i in range(len(tree1))]