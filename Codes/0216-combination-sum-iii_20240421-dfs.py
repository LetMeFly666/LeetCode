'''
Author: LetMeFly
Date: 2024-04-21 13:58:45
LastEditors: LetMeFly
LastEditTime: 2024-04-21 14:04:18
'''
from typing import List

class Solution:
    def dfs(self, k: int, n: int, index: int) -> None:
        if not k and not n:
            self.ans.append(self.now[:])
            return
        if index > n or index == 10 or k <= 0:
            return
        self.dfs(k, n, index + 1)
        self.now.append(index)
        self.dfs(k - 1, n - index, index + 1)
        self.now.pop()
    
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.ans = []
        self.now = []
        self.dfs(k, n, 1)
        return self.ans
