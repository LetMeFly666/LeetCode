'''
Author: LetMeFly
Date: 2024-11-16 13:14:52
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-16 13:21:10
'''
from typing import List

class Solution:
    def minFlips(self, grid: List[List[int]]) -> int:
        ans = 0
        n, m = len(grid), len(grid[0])
        for i in range(n // 2):
            for j in range(m // 2):
                cnt1 = grid[i][j] + grid[i][m - j - 1] + grid[n - i - 1][j] + grid[n - i - 1][m - j - 1]
                ans += min(cnt1, 4 - cnt1)
        if n % 2 and m % 2:
            ans += grid[n // 2][m // 2]
        cnt11, cnt1001 = 0, 0
        if n % 2:
            for j in range(m // 2):
                if grid[n // 2][j] == grid[n // 2][m - j - 1]:
                    if grid[n // 2][j] == 1:
                        cnt11 += 1
                else:
                    cnt1001 += 1
        if m % 2:
            for i in range(n // 2):
                if grid[i][m // 2] == grid[n - i - 1][m // 2]:
                    if grid[i][m // 2] == 1:
                        cnt11 += 1
                else:
                    cnt1001 += 1
        ans += cnt1001
        if cnt11 % 2 and not cnt1001:
            ans += 2
        return ans