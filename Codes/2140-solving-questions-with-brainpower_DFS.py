'''
Author: LetMeFly
Date: 2025-04-03 23:28:40
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-03 23:31:54
'''
from functools import cache
from typing import List


class Solution:
    @cache
    def dfs(self, i: int) -> int:
        if i >= len(self.q):
            return 0
        return max(self.dfs(i + 1), self.dfs(i + self.q[i][1] + 1) + self.q[i][0])

    def mostPoints(self, questions: List[List[int]]) -> int:
        self.q = questions
        return self.dfs(0)
