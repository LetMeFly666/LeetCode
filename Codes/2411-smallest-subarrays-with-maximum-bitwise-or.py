'''
Author: LetMeFly
Date: 2025-07-29 23:42:57
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-30 10:14:12
'''
from typing import List

class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        lastPos = [0] * 31
        for i in range(len(nums) - 1, -1, -1):
            last = i
            for j in range(31):
                if nums[i] >> j & 1:
                    lastPos[j] = i
                else:
                    last = max(last, lastPos[j])
            ans[i] = max(ans[i], last - i + 1)
        return ans