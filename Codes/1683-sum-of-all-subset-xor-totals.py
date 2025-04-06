'''
Author: LetMeFly
Date: 2025-04-06 16:17:34
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-06 16:17:54
'''
from typing import List

class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        ans = 0
        for i in range(1 << len(nums)):
            thisCnt = 0
            for j in range(len(nums)):
                if i >> j & 1:
                    thisCnt ^= nums[j]
            ans += thisCnt
        return ans