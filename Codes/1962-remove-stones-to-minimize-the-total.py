'''
Author: LetMeFly
Date: 2023-12-23 09:39:45
LastEditors: LetMeFly
LastEditTime: 2023-12-23 09:49:03
'''
from typing import List
import heapq

class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        for i in range(len(piles)):
            piles[i] *= -1
        heapq.heapify(piles)
        for _ in range(k):
            heapq.heapreplace(piles, piles[0] // 2)  # 负数向下取整 = 负的 正数向上取整
        return -sum(piles)
