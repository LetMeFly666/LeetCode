'''
Author: LetMeFly
Date: 2024-03-06 09:49:57
LastEditors: LetMeFly
LastEditTime: 2024-03-06 09:50:13
'''
from typing import List


class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        ans = 0
        for i in range(31):
            cnt = 0
            for t in nums:
                cnt += ((t >> i) & 1)
            if cnt >= k:
                ans |= (1 << i)
        return ans
