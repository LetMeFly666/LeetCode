'''
Author: LetMeFly
Date: 2026-09-21 10:32:28
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-21 13:42:03
'''
from typing import List

class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        dp = [0] * k
        ans = [0] * k
        for t in nums:
            t %= k
            dp2 = [0] * k
            for i in range(k):
                dp2[i] += dp[i * t % k]
            dp2[t] += 1
            for i, v in enumerate(dp2):
                ans[i] += v
            dp = dp2
        return ans
