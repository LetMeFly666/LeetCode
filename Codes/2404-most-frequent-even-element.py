'''
Author: LetMeFly
Date: 2023-04-13 13:11:01
LastEditors: LetMeFly
LastEditTime: 2023-04-13 18:15:33
'''
from typing import List

class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        nums.sort()
        M, ans = 0, -1
        beginLoc = 0
        for i in range(1, len(nums) + 1):
            if i == len(nums) or nums[i] != nums[i - 1]:
                if nums[i - 1] % 2 == 0:
                    thisCnt = i - beginLoc
                    if thisCnt > M:
                        M = thisCnt
                        ans = nums[i - 1]
                beginLoc = i
        return ans