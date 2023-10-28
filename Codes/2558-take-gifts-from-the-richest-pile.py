'''
Author: LetMeFly
Date: 2023-10-28 09:51:39
LastEditors: LetMeFly
LastEditTime: 2023-10-28 09:57:11
'''
from typing import List
from math import sqrt
import heapq

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        for i in range(len(gifts)):
            gifts[i] = -gifts[i]
        heapq.heapify(gifts)
        for _ in range(k):
            thisGift = heapq.heappop(gifts)
            heapq.heappush(gifts, -int(sqrt(-thisGift)))
        return -sum(gifts)
