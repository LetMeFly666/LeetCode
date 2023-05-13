'''
Author: LetMeFly
Date: 2023-05-13 13:17:45
LastEditors: LetMeFly
LastEditTime: 2023-05-13 13:19:57
'''
from typing import List

class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        se = set(nums)
        ans = -1
        for num in nums:
            if num > 0 and -num in se:
                ans = max(ans, num)
        return ans