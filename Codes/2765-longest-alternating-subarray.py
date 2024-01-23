'''
Author: LetMeFly
Date: 2024-01-23 22:22:14
LastEditors: LetMeFly
LastEditTime: 2024-01-23 22:25:36
'''
from typing import List

class Solution:
    def get1(self, oddLoc=1) -> int:
        evenLoc = -oddLoc
        ans = 1
        cnt = 1
        for i in range(len(self.nums)):
            shouldAdd = oddLoc if i % 2 else evenLoc
            if i + 1 == len(self.nums) or self.nums[i + 1] != self.nums[i] + shouldAdd or (cnt == 1 and shouldAdd == -1):
                ans = max(ans, cnt)
                cnt = 1
            else:
                cnt += 1
        return ans

    def alternatingSubarray(self, nums: List[int]) -> int:
        self.nums = nums
        ans = max(self.get1(), self.get1(-1))
        return ans if ans >= 2 else -1