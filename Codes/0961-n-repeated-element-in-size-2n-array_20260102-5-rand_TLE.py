'''
Author: LetMeFly
Date: 2026-01-02 17:13:12
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-02 17:14:28
'''
from typing import List
from random import randrange

# THIS CANNOT ACCESS
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        n = len(nums) - 1
        while True:
            loc1 = randrange(0, n)
            loc2 = randrange(0, n)
            if loc1 != loc2 and nums[loc1] == nums[loc2]:
                return nums[loc1]