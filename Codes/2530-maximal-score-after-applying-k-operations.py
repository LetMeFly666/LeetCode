'''
Author: LetMeFly
Date: 2023-10-18 09:17:15
LastEditors: LetMeFly
LastEditTime: 2023-10-18 09:27:01
'''
from typing import List
import heapq

class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        nums = list(map(lambda x: -x, nums))
        heapq.heapify(nums)
        ans = 0
        for _ in range(k):
            thisNum = -heapq.heappop(nums)
            ans += thisNum
            heapq.heappush(nums, -((thisNum + 2) // 3))
        return ans
