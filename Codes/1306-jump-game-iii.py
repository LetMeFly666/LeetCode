'''
Author: LetMeFly
Date: 2026-05-17 09:51:20
LastEditors: LetMeFly.xyz
LastEditTime: 2026-05-17 10:43:30
'''
from typing import List
from functools import cache

class Solution:
    @cache
    def dfs(self, start: int) -> bool:
        if not self.arr[start]:
            return True
        if start - self.arr[start] >= 0 and self.dfs(start - self.arr[start]):
            return True
        if start + self.arr[start] < len(self.arr) and self.dfs(start + self.arr[start]):
            return True
        return False
    
    def canReach(self, arr: List[int], start: int) -> bool:
        self.arr = arr
        return self.dfs(start)
