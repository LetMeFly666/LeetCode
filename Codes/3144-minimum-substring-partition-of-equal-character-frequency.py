'''
Author: LetMeFly
Date: 2024-08-28 23:10:11
LastEditors: LetMeFly
LastEditTime: 2024-08-28 23:12:54
'''
from collections import defaultdict

class Solution:
    def minimumSubstringsInPartition(self, s: str) -> int:
        dp = [100000] * (len(s) + 1)
        dp[0] = 0
        ma = defaultdict(int)
        for i in range(len(s)):
            ma.clear()
            types, maxTimes = 0, 0
            for j in range(i, -1, -1):
                ma[s[j]] += 1
                maxTimes = max(maxTimes, ma[s[j]])
                if ma[s[j]] == 1:
                    types += 1
                if maxTimes * types == i - j + 1:
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1)
        return dp[-1]