'''
Author: LetMeFly
Date: 2023-02-27 09:35:51
LastEditors: LetMeFly
LastEditTime: 2023-02-27 09:38:00
'''
from typing import List

class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        ansOdd, ansEven = 0, 0
        for i in range(len(nums)):
            if i % 2:
                ansOdd += max(0, nums[i] - nums[i - 1] + 1, nums[i] - nums[i + 1] + 1 if i + 1 < len(nums) else 0)
            else:
                ansEven += max(0, nums[i] - nums[i - 1] + 1 if i - 1 >= 0 else 0, nums[i] - nums[i + 1] + 1 if i + 1 < len(nums) else 0)
        return min(ansOdd, ansEven)