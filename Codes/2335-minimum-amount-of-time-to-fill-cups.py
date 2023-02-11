'''
Author: LetMeFly
Date: 2023-02-11 09:56:49
LastEditors: LetMeFly
LastEditTime: 2023-02-11 10:00:18
'''
from typing import List

class Solution:
    def fillCups(self, amount: List[int]) -> int:
        amount.sort()
        if amount[0] + amount[1] <= amount[2]:
            return amount[2]
        return (amount[0] + amount[1] + amount[2] + 1) // 2