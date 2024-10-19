'''
Author: LetMeFly
Date: 2024-10-19 09:26:40
LastEditors: LetMeFly
LastEditTime: 2024-10-19 09:26:41
'''
from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        ans, original = 0, 1
        for t in nums:
            if t ^ original:
                ans += 1
                original ^= 1
        return ans