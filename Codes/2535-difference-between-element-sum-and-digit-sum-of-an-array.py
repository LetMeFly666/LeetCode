'''
Author: LetMeFly
Date: 2024-09-26 18:07:21
LastEditors: LetMeFly
LastEditTime: 2024-09-26 18:08:59
'''
from typing import List

class Solution:
    def getSum(self, x: int) -> int:
        ans = 0
        while x:
            ans += x % 10
            x //= 10
        return ans

    def differenceOfSum(self, nums: List[int]) -> int:
        x = y = 0
        for t in nums:
            x += t
            y += self.getSum(t)
        return abs(x - y)