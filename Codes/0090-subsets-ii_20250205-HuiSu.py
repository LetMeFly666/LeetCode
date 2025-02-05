'''
Author: LetMeFly
Date: 2025-02-05 12:29:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-05 12:32:04
'''
from typing import List

class Solution:
    def dfs(self, loc: int) -> None:
        if loc == len(self.a):
            self.ans.append([i for i in self.now])
            return
        # 选当前
        self.now.append(self.a[loc])
        self.dfs(loc + 1)
        self.now.pop()
        # 不选当前
        next = loc + 1
        while next < len(self.a) and self.a[next] == self.a[loc]:
            next += 1
        self.dfs(next)
    
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        self.ans: List[List[int]] = []
        self.a = sorted(nums)
        self.now = []
        self.dfs(0)
        return self.ans