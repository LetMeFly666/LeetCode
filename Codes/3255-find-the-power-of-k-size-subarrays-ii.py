'''
Author: LetMeFly
Date: 2024-11-07 12:20:10
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-07 12:23:05
'''
from typing import List

class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * (len(nums) - k + 1)
        notCoutinue = sum(nums[i] != nums[i -  1] + 1 for i in range(1, k))
        ans[0] = -1 if notCoutinue else nums[k - 1]
        for i in range(1, len(nums) - k + 1):
            notCoutinue -= nums[i] != nums[i - 1] + 1
            notCoutinue += nums[i + k - 1] != nums[i + k - 2] + 1
            ans[i] = -1 if notCoutinue else nums[i + k - 1]
        return ans