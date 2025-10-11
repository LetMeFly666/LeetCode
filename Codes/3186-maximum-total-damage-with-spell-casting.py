'''
Author: LetMeFly
Date: 2025-10-11 18:10:29
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-11 18:46:52
'''
from typing import List
from collections import Counter

class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        cnt = Counter(power)
        values = sorted(cnt)
        dp = [0] * (len(values) + 1)
        j = 0
        for i, val in enumerate(values):
            while values[j] < val - 2:
                j += 1
            dp[i + 1] = max(dp[i], dp[j] + val * cnt[val])
        return dp[-1]