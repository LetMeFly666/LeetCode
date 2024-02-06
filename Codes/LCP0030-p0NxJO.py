'''
Author: LetMeFly
Date: 2024-02-06 10:36:18
LastEditors: LetMeFly
LastEditTime: 2024-02-06 10:43:23
'''
from typing import List
import heapq

class Solution:
    def magicTower(self, nums: List[int]) -> int:
        pq = []
        now = 1
        totalNegative = 0
        ans = 0
        for t in nums:
            if t < 0:
                heapq.heappush(pq, t)
            now += t
            while now <= 0 and pq:
                thisNegative = -heapq.heappop(pq)
                totalNegative += thisNegative
                now += thisNegative
                ans += 1
            if now <= 0:
                return -1
        return ans if now > totalNegative else -1
