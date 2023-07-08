'''
Author: LetMeFly
Date: 2023-07-09 07:21:43
LastEditors: LetMeFly
LastEditTime: 2023-07-09 07:34:47
'''
from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[l] + nums[r]
                if s == target:
                    ans.append([nums[i], nums[l], nums[r]])
                    while l + 1 < r and nums[l + 1] == nums[l]:
                        l += 1
                    while r - 1 > l and nums[r - 1] == nums[r]:
                        r -= 1
                    l += 1
                    r -= 1
                elif s < target:
                    l += 1
                else:
                    r -= 1
        return ans