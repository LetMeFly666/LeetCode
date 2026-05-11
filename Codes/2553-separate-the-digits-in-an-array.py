'''
Author: LetMeFly
Date: 2026-05-11 21:16:18
LastEditors: LetMeFly.xyz
LastEditTime: 2026-05-11 21:18:21
'''
from typing import List

class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for x in reversed(nums):
            while x:
                ans.append(x % 10)
                x //= 10
        return reversed(ans)
