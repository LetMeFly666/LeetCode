'''
Author: LetMeFly
Date: 2023-07-20 08:14:46
LastEditors: LetMeFly
LastEditTime: 2023-07-20 08:24:33
'''
from typing import List

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        nowM, M = nums[0], nums[0]
        nowm, m = nums[0], nums[0]
        s = nums[0]
        for i in range(1, len(nums)):
            nowM = max(nowM + nums[i], nums[i])
            M = max(M, nowM)
            nowm = min(nowm + nums[i], nums[i])
            m = min(m, nowm)
            s += nums[i]
        return M if M < 0 else max(M, s - m)