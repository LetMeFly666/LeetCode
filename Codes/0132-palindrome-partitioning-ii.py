'''
Author: LetMeFly
Date: 2025-03-02 12:26:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-02 12:33:40
'''
class Solution:
    def minCut(self, s: str) -> int:
        isOk = [[True] * len(s) for _ in range(len(s))]
        for i in range(len(s) - 1, -1, -1):
            for j in range(i + 1, len(s)):
                isOk[i][j] = s[i] == s[j] and isOk[i + 1][j - 1]
        
        dp = [100000] * len(s)
        for i in range(len(s)):
            if isOk[0][i]:
                dp[i] = 0
                continue
            for j in range(i):
                if isOk[j + 1][i]:
                    dp[i] = min(dp[i], dp[j] + 1)
        return dp[-1]
