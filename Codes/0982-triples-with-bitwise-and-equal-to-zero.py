'''
Author: LetMeFly
Date: 2023-03-04 14:21:58
LastEditors: LetMeFly
LastEditTime: 2023-03-04 14:23:47
'''
from collections import Counter
from typing import List

class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        two = Counter((x & y) for x in nums for y in nums)
        ans = 0
        for one in nums:
            for mask, times in two.items():
                if (one & mask) == 0:
                    ans += times
        return ans