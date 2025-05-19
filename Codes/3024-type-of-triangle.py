'''
Author: LetMeFly
Date: 2025-05-19 13:22:46
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-19 13:30:25
'''
from typing import List

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        nums.sort()
        a, b, c = nums
        if a + b <= c:
            return "none"
        if a == b == c:
            return "equilateral"
        if a == b or b == c:
            return "isosceles"
        return "scalene"