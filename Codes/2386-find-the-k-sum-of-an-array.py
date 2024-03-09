'''
Author: LetMeFly
Date: 2024-03-09 18:27:07
LastEditors: LetMeFly
LastEditTime: 2024-03-09 18:31:32
'''
from typing import List
import heapq

class Solution:
    def kSum(self, nums: List[int], k: int) -> int:
        sum_ = 0
        for i in range(len(nums)):
            if nums[i] >= 0:
                sum_ += nums[i]
            else:
                nums[i] = -nums[i]
        nums.sort()
        pq = [(nums[0], 0)]
        toDesc = 0
        for _ in range(1, k):
            nowSum, th = heapq.heappop(pq)
            toDesc = nowSum
            if th == len(nums) - 1:
                continue
            heapq.heappush(pq, (nowSum + nums[th + 1], th + 1))
            heapq.heappush(pq, (nowSum - nums[th] + nums[th + 1], th + 1))
        return sum_ - toDesc
