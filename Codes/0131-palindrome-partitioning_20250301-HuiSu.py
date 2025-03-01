'''
Author: LetMeFly
Date: 2025-03-01 16:13:32
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-01 16:17:40
'''
from typing import List

class Solution:
    def ok(self, s: str) -> bool:
        for i in range(len(s) // 2):
            if s[i] != s[len(s) - i - 1]:
                return False
        return True

    def dfs(self, l: int) -> None:
        if l == len(self.s):
            self.ans.append([i for i in self.now])
            return
        for r in range(l, len(self.s)):
            temp = self.s[l:r + 1]
            if self.ok(temp):
                self.now.append(temp)
                self.dfs(r + 1)
                self.now.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.ans: List[List[str]] = []
        self.now: List[str] = []
        self.s = s
        self.dfs(0)
        return self.ans