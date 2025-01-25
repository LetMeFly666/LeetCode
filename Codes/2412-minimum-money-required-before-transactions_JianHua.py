'''
Author: LetMeFly
Date: 2025-01-25 10:00:39
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-25 10:02:46
'''
from typing import List

class Solution:
    def minimumMoney(self, transactions: List[List[int]]) -> int:
        return sum(max(0, c - e) for c, e in transactions) + max(min(t) for t in transactions)