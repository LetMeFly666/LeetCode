'''
Author: LetMeFly
Date: 2023-01-15 08:37:40
LastEditors: LetMeFly
LastEditTime: 2023-01-15 08:37:42
'''
from typing import List


class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        newNum = []
        loc = 0
        isMin = True
        while loc < len(nums):
            if isMin:
                newNum.append(min(nums[loc], nums[loc + 1]))
                isMin = False
            else:
                newNum.append(max(nums[loc], nums[loc + 1]))
                isMin = True
            loc += 2
        return self.minMaxGame(newNum)