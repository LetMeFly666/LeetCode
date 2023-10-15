'''
Author: LetMeFly
Date: 2023-10-15 19:37:29
LastEditors: LetMeFly
LastEditTime: 2023-10-15 19:39:33
'''
from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        cnt = [0] * 32
        for t in nums:
            for i in range(32):
                cnt[i] += ((t >> i) & 1)
        ans = 0
        for i in range(32):
            ans += (1 << i) * (cnt[i] % 3)
        return ans