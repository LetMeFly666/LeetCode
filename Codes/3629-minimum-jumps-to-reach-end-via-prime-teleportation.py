'''
Author: LetMeFly
Date: 2026-05-08 20:58:17
LastEditors: LetMeFly.xyz
LastEditTime: 2026-05-08 21:10:33
'''
from typing import List
from collections import defaultdict
from itertools import count

M = 1000001
primes = [[] for _ in range(M)]
for i in range(2, M):
    if not primes[i]:
        for j in range(i, M, i):
            primes[j].append(i)


class Solution:
    def push(self, q: List[int], n: int):
        if self.visited[n]:
            return
        q.append(n)
        self.visited[n] = True
    
    def minJumps(self, nums: List[int]) -> int:
        jumps = defaultdict(list)
        for i in range(len(nums)):
            for p in primes[nums[i]]:
                jumps[p].append(i)

        q = []
        self.visited = [False] * len(nums)
        self.push(q, 0)
        for ans in count(0):
            next_queue = []
            for now in q:
                if now == len(nums) - 1:
                    return ans
                self.push(next_queue, now + 1)
                if now:
                    self.push(next_queue, now - 1)
                for next in jumps[nums[now]]:
                    self.push(next_queue, next)
                jumps[nums[now]].clear()
            q = next_queue
