'''
Author: LetMeFly
Date: 2023-06-05 12:41:55
LastEditors: LetMeFly
LastEditTime: 2023-06-05 12:49:13
'''
from typing import List

class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        for i in range(0, len(nums) - 1):
            if nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0
        ans = []
        for i in nums:
            if i:
                ans.append(i)
        ans += [0] * (len(nums) - len(ans))
        return ans