'''
Author: LetMeFly
Date: 2024-11-02 21:48:09
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-02 21:52:34
'''
from typing import List

class Solution:
    def union(self, x: int, y: int) -> None:
        self.fa[self.find(x)] = self.find(y)
    
    def find(self, x: int) -> int:
        if self.fa[x] != x:
            self.fa[x] = self.find(self.fa[x])
        return self.fa[x]

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        self.fa = [i for i in range(len(edges) + 1)]
        for x, y in edges:
            if self.find(x) == self.find(y):
                return [x, y]
            else:
                self.union(x, y)
        return []  # FAKE RETURN
