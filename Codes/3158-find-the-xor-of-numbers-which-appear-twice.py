'''
Author: LetMeFly
Date: 2024-10-12 14:29:56
LastEditors: LetMeFly
LastEditTime: 2024-10-12 14:30:37
'''
from typing import List

class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ans = ma = 0
        for t in nums:
            if ma >> t & 1:
                ans ^= t
            else:
                ma |= 1 << t
        return ans