'''
Author: LetMeFly
Date: 2025-05-23 23:35:45
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-23 23:52:09
'''
from typing import List
import heapq

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        queries.sort()
        diff = [0] * (len(nums) + 1)
        cnt = iq = 0
        pq = []
        for inum in range(len(nums)):
            cnt += diff[inum]
            while iq < len(queries) and queries[iq][0] <= inum:
                heapq.heappush(pq, -queries[iq][1])
                iq += 1
            while cnt < nums[inum] and len(pq) and -pq[0] >= inum:
                cnt += 1
                diff[-heapq.heappop(pq) + 1] -= 1
            if cnt < nums[inum]:
                return -1
        return len(pq)