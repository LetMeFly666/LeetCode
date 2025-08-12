'''
Author: LetMeFly
Date: 2025-08-12 09:48:56
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-12 21:37:06
'''
class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        dp = [1] + [0] * n
        th = 1
        while True:
            p = th ** x
            if p > n:
                break
            th += 1
            for i in range(n, p - 1, -1):
                dp[i] += dp[i - p]
        return dp[-1] % 1000000007