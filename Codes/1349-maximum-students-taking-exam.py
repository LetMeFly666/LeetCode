'''
Author: LetMeFly
Date: 2023-12-26 10:10:36
LastEditors: LetMeFly
LastEditTime: 2023-12-26 10:42:43
'''
from typing import List
from functools import cache

class Solution:
    @cache
    def dfs(self, row: int, status: int) -> int:
        for j in range(self.n):
            if not status & (1 << j):
                continue
            if self.seats[row][j] == '#':  # 坏椅子坐人
                return -1000
            if j > 0 and status & (1 << (j - 1)):  # 连续两人
                return -1000
        cnt1 = bin(status).count('1')
        if not row:
            return cnt1
        lastRowMax = 0
        for lastStatus in range(1 << self.n):
            ok = True
            for j in range(self.n):
                if j > 0 and status & (1 << j) and lastStatus & (1 << (j - 1)):
                    ok = False
                    break
                if j + 1 < self.n and status & (1 << j) and lastStatus & (1 << (j + 1)):
                    ok = False
                    break
            if ok:
                lastRowMax = max(lastRowMax, self.dfs(row - 1, lastStatus))
        return cnt1 + lastRowMax
    
    def maxStudents(self, seats: List[List[str]]) -> int:
        self.seats = seats
        self.m, self.n = len(seats), len(seats[0])
        ans = 0
        for status in range(1 << self.n):
            ans = max(ans, self.dfs(self.m - 1, status))
        return ans
