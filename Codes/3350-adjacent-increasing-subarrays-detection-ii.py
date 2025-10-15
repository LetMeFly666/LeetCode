'''
Author: LetMeFly
Date: 2025-10-15 22:07:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-15 22:23:10
'''
from typing import List

class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        ans = lastCnt = nowCnt = 0
        for i in range(len(nums)):
            nowCnt += 1
            if i == len(nums) - 1 or nums[i] >= nums[i + 1]:
                ans = max(ans, min(lastCnt, nowCnt), nowCnt // 2)
                lastCnt = nowCnt
                nowCnt = 0
        return ans