'''
Author: LetMeFly
Date: 2024-10-13 23:50:12
LastEditors: LetMeFly
LastEditTime: 2024-10-13 23:52:19
'''
class Solution:
    def twoEggDrop(self, n: int) -> int:
        dp = [0] + [10000] * n
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                dp[i] = min(dp[i], max(j, dp[i - j] + 1))
        return dp[-1]