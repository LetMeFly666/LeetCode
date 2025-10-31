'''
Author: LetMeFly
Date: 2025-10-31 22:19:33
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-31 22:21:51
'''
from typing import List

class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        se = set()
        ans = []
        for t in nums:
            if t in se:
                ans.append(t)
            else:
                se.add(t)
        return ans