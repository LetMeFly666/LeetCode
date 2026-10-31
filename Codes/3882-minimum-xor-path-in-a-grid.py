'''
Author: LetMeFly
Date: 2026-10-28 14:47:39
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-31 12:47:36
'''
class Solution:
    def transfer(self, a: int, b: int, val: int) -> int:
        while a:
            lowbit = a & -a
            length = lowbit.bit_length() - 1
            a ^= lowbit
            b |= 1 << (length ^ val)
        return b

    def minCost(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]
        dp[0][0] = 1 << grid[0][0]
        for i in range(n):
            for j in range(m):
                if i:
                    dp[i][j] = self.transfer(dp[i - 1][j], dp[i][j], grid[i][j])
                if j:
                    dp[i][j] = self.transfer(dp[i][j - 1], dp[i][j], grid[i][j])
        ans = dp[-1][-1]
        return (ans & -ans).bit_length() - 1
