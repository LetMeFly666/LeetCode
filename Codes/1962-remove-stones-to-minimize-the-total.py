'''
Author: LetMeFly
Date: 2023-12-23 09:39:45
LastEditors: LetMeFly
LastEditTime: 2023-12-23 09:42:52
'''
from typing import List
import heapq

class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        for i in range(len(piles)):
            piles[i] *= -1
        heapq.heapify(piles)
        for _ in range(k):
            heapq.heappush(piles, -((-heapq.heappop(piles) + 1) // 2))
        return -sum(piles)
