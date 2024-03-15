'''
Author: LetMeFly
Date: 2024-03-15 18:08:41
LastEditors: LetMeFly
LastEditTime: 2024-03-15 18:16:38
'''
from typing import List

class Solution:  # AC,96.77%,100.00%
    def sellingWood(self, m: int, n: int, prices: List[List[int]]) -> int:
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for x, y, p in prices:
            dp[x][y] = p
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = max(
                    dp[i][j],
                    max((dp[i - k][j] + dp[k][j] for k in range(1, i // 2 + 1)), default=0),  # 这里必须加上default，否则可能会变成max(())
                    max((dp[i][j - k] + dp[i][k] for k in range(1, j // 2 + 1)), default=0)
                )
        return dp[m][n]
