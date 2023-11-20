'''
Author: LetMeFly
Date: 2023-11-20 10:57:24
LastEditors: LetMeFly
LastEditTime: 2023-11-20 10:57:26
'''
from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans, cnt = nums[0], nums[0]
        for i in range(1, len(nums)):
            cnt = max(cnt + nums[i], nums[i])
            ans = max(ans, cnt)
        return ans