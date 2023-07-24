'''
Author: LetMeFly
Date: 2023-07-25 06:22:27
LastEditors: LetMeFly
LastEditTime: 2023-07-25 06:33:59
'''
from typing import List
import heapq

class Solution:
    def halveArray(self, nums: List[int]) -> int:
        pq = []
        s = 0
        for t in nums:
            heapq.heappush(pq, -t)
            s += t
        need = s / 2
        ans = 0
        while need > 0:
            thisValue = -heapq.heappop(pq)
            thisValue /= 2
            need -= thisValue
            ans += 1
            heapq.heappush(pq, -thisValue)
        return ans