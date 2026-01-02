'''
Author: LetMeFly
Date: 2026-01-02 17:04:11
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-02 17:04:20
'''
from typing import List

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        ans, hp = -1, 0
        for t in nums[1:]:
            if t == nums[0]:
                return t
            if not hp:
                ans, hp = t, 1
            elif ans == t:
                hp += 1
            else:
                hp -= 1
        return ans