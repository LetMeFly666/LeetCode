'''
Author: LetMeFly
Date: 2025-03-03 13:30:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-03 13:36:20
'''
class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)
        minop = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                minop[i][j] = (s[i] != s[j]) + minop[i + 1][j - 1]
        dp = [[1000] * k for _ in range(n)]
        dp[0][0] = 0
        for i in range(n):
            dp[i][0] = minop[0][i]
        for i in range(1, n):
            for j in range(1, min(k, i + 1)):
                for i0 in range(i):
                    dp[i][j] = min(dp[i][j], dp[i0][j - 1] + minop[i0 + 1][i])
        return dp[-1][-1]