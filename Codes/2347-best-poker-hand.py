'''
Author: LetMeFly
Date: 2023-02-20 07:56:09
LastEditors: LetMeFly
LastEditTime: 2023-02-20 08:07:50
'''
from typing import List


class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if suits[0] == suits[1] == suits[2] ==suits[3] == suits[4]:
            return "Flush"
        ranks.sort()
        maxSame, theSame = 1, 1
        for i in range(1, 5):
            if ranks[i] == ranks[i - 1]:
                theSame += 1
                maxSame = max(maxSame, theSame)
            else:
                theSame = 1
        if maxSame >= 3:
            return "Three of a Kind"
        if maxSame == 2:
            return "Pair"
        return "High Card"