'''
Author: LetMeFly
Date: 2026-10-17 16:31:28
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-17 19:00:47
'''
from typing import List

class Union:
    def __init__(self, n: int) -> None:
        self.parent = [i for i in range(n)]
        self.sz = [1] * n
        self.count = n
    
    def merge(self, x: int, y: int) -> None:
        px = self.find(x)
        py = self.find(y)
        if px == py:
            return
        if self.sz[px] > self.sz[py]:
            px, py = py, px
        self.sz[py] += self.sz[px]
        self.count -= 1
    
    def find(self, x: int) -> int:
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

class Solution:
    def _getSum(self, n: int) -> int:
        ans = 0
        while n:
            ans += n % 10
            n //= 10
        return ans
        
    def minSwaps(self, nums: List[int]) -> int:
        n = len(nums)
        idxs = [i for i in range(n)]
        idxs.sort(key=lambda x: (self._getSum(x), x))
        
        union = Union(n)
        for i in range(n):
            union.merge(i, idxs[i])
        return n - union.count
