'''
Author: LetMeFly
Date: 2024-05-25 12:39:14
LastEditors: LetMeFly
LastEditTime: 2024-05-25 12:39:23
'''
from typing import List

class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i, len(nums)):
                if j - i >= indexDifference and abs(nums[i] - nums[j]) >= valueDifference:
                    return [i, j]
        return [-1, -1]