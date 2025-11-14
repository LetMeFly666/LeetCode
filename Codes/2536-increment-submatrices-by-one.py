'''
Author: LetMeFly
Date: 2025-11-14 17:51:14
LastEditors: LetMeFly.xyz
LastEditTime: 2025-11-14 19:16:40
'''
from typing import List

class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        diff = [[0] * (n + 1) for _ in range(n + 1)]
        for x1, y1, x2, y2 in queries:
            diff[x1][y1] += 1
            diff[x2 + 1][y1] -= 1
            diff[x1][y2 + 1] -= 1
            diff[x2 + 1][y2 + 1] += 1
        ans = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                ans[i][j] = diff[i][j] + \
                            (0 if not i else ans[i - 1][j]) + \
                            (0 if not j else ans[i][j - 1]) - \
                            (0 if not i or not j else ans[i - 1][j - 1])
        return ans