'''
Author: LetMeFly
Date: 2024-03-25 10:23:58
LastEditors: LetMeFly
LastEditTime: 2024-03-25 10:25:26
'''
from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        for coin in coins:
            for i in range(coin, amount + 1):
                dp[i] += dp[i - coin]
        return dp[-1]
