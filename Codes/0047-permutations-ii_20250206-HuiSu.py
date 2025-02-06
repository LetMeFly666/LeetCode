'''
Author: LetMeFly
Date: 2025-02-06 13:57:31
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-06 14:07:13
'''
from typing import List

class Solution:
    def dfs(self, n: int) -> None:
        if n == len(self.nums):
            self.ans.append([i for i in self.now])
            return
        for i in range(len(self.nums)):
            if self.visited[i] or i and self.nums[i] == self.nums[i - 1] and not self.visited[i - 1]:
                continue
            self.now.append(self.nums[i])
            self.visited[i] = True
            self.dfs(n + 1)
            self.visited[i] = False
            self.now.pop()
    
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.nums = sorted(nums)
        self.ans: List[List[int]] = []
        self.now: List[int] = []
        self.visited = [False] * len(nums)
        self.dfs(0)
        return self.ans