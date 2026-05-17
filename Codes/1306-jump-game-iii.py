'''
Author: LetMeFly
Date: 2026-05-17 09:51:20
LastEditors: LetMeFly.xyz
LastEditTime: 2026-05-17 10:46:40
'''
from typing import List

class Solution:
    def dfs(self, start: int) -> bool:
        if self.visited[start]:
            return False
        self.visited[start] = True
        if not self.arr[start]:
            return True
        if start - self.arr[start] >= 0 and self.dfs(start - self.arr[start]):
            return True
        if start + self.arr[start] < len(self.arr) and self.dfs(start + self.arr[start]):
            return True
        return False
    
    def canReach(self, arr: List[int], start: int) -> bool:
        self.arr = arr
        self.visited = [False] * len(arr)
        return self.dfs(start)
