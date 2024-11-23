'''
Author: LetMeFly
Date: 2024-11-23 10:14:35
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-23 10:16:22
'''
from typing import List

class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        cnt = [[0] * 11 for _ in range(n)]
        for a, b in pick:
            cnt[a][b] += 1
        return sum(any(cnt[i][j] > i for j in range(11)) for i in range(n))