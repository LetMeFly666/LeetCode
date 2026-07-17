'''
Author: LetMeFly
Date: 2026-07-18 07:00:55
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-18 07:04:07
'''
from typing import List
from math import gcd

class Solution:
    def findGCD(self, nums: List[int]) -> int:
        return gcd(min(nums), max(nums))
