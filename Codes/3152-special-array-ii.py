'''
Author: LetMeFly
Date: 2024-08-14 23:34:09
LastEditors: LetMeFly
LastEditTime: 2024-08-14 23:35:38
'''
from typing import List

class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        cnt = 0
        for i in range(len(nums) - 1):
            same = nums[i] % 2 == nums[i + 1] % 2
            nums[i] = cnt
            cnt += same
        nums[-1] = cnt
        return [nums[a] == nums[b] for a, b in queries]