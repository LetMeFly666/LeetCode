'''
Author: LetMeFly
Date: 2023-10-14 11:12:21
LastEditors: LetMeFly
LastEditTime: 2023-10-14 11:13:02
'''
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for t in nums:
            ans ^= t
        return ans
