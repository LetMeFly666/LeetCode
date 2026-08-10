'''
Author: LetMeFly
Date: 2026-08-10 11:40:46
LastEditors: LetMeFly.xyz
LastEditTime: 2026-08-10 11:53:22
'''
from functools import cache

@cache
def dfs(n: int) -> bool:
    if not n:
        return False
    x = 1
    while x * x <= n:
        if not dfs(n - x * x):
            return True
        x += 1
    return False

class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        return dfs(n)
