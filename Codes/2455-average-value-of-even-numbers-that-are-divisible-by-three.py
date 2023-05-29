'''
Author: LetMeFly
Date: 2023-05-29 10:22:22
LastEditors: LetMeFly
LastEditTime: 2023-05-29 10:25:53
'''
from typing import List

class Solution:
    def averageValue(self, nums: List[int]) -> int:
        cnt = 0
        s = 0
        for t in nums:
            if t % 6 == 0:
                s += t
                cnt += 1
        return s // cnt if cnt else 0