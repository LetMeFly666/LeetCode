'''
Author: LetMeFly
Date: 2024-04-06 12:40:18
LastEditors: LetMeFly
LastEditTime: 2024-04-06 12:45:59
'''
from typing import List


Log = 16

class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.ancestors = [[parent[i]] + [-1] * (Log - 1) for i in range(n)]
        for j in range(1, Log):
            for i in range(n):
                if self.ancestors[i][j - 1] != -1:
                    self.ancestors[i][j] = self.ancestors[self.ancestors[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for j in range(Log):
            if (k >> j) & 1:
                node = self.ancestors[node][j]
            if node == -1:
                break
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)