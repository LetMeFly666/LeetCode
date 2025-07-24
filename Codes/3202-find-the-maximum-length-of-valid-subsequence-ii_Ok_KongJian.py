'''
Author: LetMeFly
Date: 2025-07-21 22:50:12
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-21 22:57:04
'''
from typing import List

class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        ans = 0
        for res in range(k):
            dp = [0] * k
            for x in nums:
                x %= k
                # (1+2) % 5 = 3 | (4 + (3 - 4 + 5)) % 5 = 3 | 3 - 4 + 5 = 4 | 3 - 4 = -1 | [0, 1, 2, 3, 4][-1] = [0, 1, 2, 3, 4][4]
                dp[res - x] = dp[x] + 1
            ans = max(ans, max(dp))
        return ans