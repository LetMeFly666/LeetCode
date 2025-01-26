'''
Author: LetMeFly
Date: 2025-01-26 07:58:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-26 08:01:59
'''
from typing import List

class Solution:
    def dfs(self, target: int, index: int) -> None:
        if not target:
            self.ans.append([i for i in self.now])
            return
        if index == len(self.c) or target < 0:
            return
        self.now.append(self.c[index])
        self.dfs(target - self.c[index], index + 1)
        self.now.pop()
        next = index + 1
        while next < len(self.c) and self.c[next] == self.c[index]:
            next += 1
        self.dfs(target, next)
    
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        self.c = candidates
        self.ans = []
        self.now = []
        self.dfs(target, 0)
        return self.ans