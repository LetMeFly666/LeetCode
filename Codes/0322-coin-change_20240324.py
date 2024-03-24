'''
Author: LetMeFly
Date: 2024-03-24 12:02:15
LastEditors: LetMeFly
LastEditTime: 2024-03-24 12:04:04
'''
from typing import List

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [int(1e5)] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return -1 if dp[-1] > amount else dp[-1]
