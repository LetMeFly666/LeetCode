'''
Author: LetMeFly
Date: 2024-03-30 22:30:47
LastEditors: LetMeFly
LastEditTime: 2024-03-30 22:32:31
'''
from typing import List

class Solution:
    def minimumAddedCoins(self, coins: List[int], target: int) -> int:
        coins.sort()
        to, ans, i = 0, 0, 0
        while to < target:
            if i < len(coins) and coins[i] <= to + 1:
                to += coins[i]
                i += 1
            else:
                to += to + 1
                ans += 1
        return ans
