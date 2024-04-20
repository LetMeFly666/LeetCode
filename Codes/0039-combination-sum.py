'''
Author: LetMeFly
Date: 2024-04-20 11:00:40
LastEditors: LetMeFly
LastEditTime: 2024-04-20 11:04:36
'''
from typing import List

class Solution:
    def dfs(self, target: int, index: int) -> None:
        if not target:
            self.ans.append(self.now[:])
            return
        if index == len(self.candidates):
            return
        # not choose
        self.dfs(target, index + 1)
        # choose
        if target >= self.candidates[index]:
            self.now.append(self.candidates[index])
            self.dfs(target - self.candidates[index], index)
            self.now.pop()        

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.ans = []
        self.now = []
        self.candidates = candidates
        self.dfs(target, 0)
        return self.ans