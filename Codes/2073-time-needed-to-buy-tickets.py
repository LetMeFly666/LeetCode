'''
Author: LetMeFly
Date: 2024-10-03 13:51:37
LastEditors: LetMeFly
LastEditTime: 2024-10-03 13:54:17
'''
from typing import List

class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        # return sum(min(t, tickets[k] if th <= k else tickets[k] - 1) for th, t in enumerate(tickets))
        return sum(min(t, tickets[k] - (th > k)) for th, t in enumerate(tickets))