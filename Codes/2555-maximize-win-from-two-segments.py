'''
Author: LetMeFly
Date: 2024-09-11 14:23:39
LastEditors: LetMeFly
LastEditTime: 2024-09-11 14:27:27
'''
from typing import List

class Solution:
    def maximizeWin(self, prizePositions: List[int], k: int) -> int:
        ans = 0
        dp = [0] * (len(prizePositions) + 1)
        l, r = 0, 0
        while r < len(prizePositions):
            while prizePositions[r] - prizePositions[l] > k:
                l += 1
            ans = max(ans, r - l + 1 + dp[l])
            dp[r + 1] = max(dp[r], r - l + 1)
            r += 1
        return ans