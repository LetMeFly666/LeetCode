'''
Author: LetMeFly
Date: 2025-10-16 19:40:17
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-16 19:55:23
'''
from typing import List
from collections import Counter

class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        cnt = Counter(x % value for x in nums)  # python负数模正数是正数
        ans = 0
        while cnt[ans % value]:
            cnt[ans % value] -= 1
            ans += 1
        return ans
