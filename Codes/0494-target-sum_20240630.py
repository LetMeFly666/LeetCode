'''
Author: LetMeFly
Date: 2024-06-30 13:47:43
LastEditors: LetMeFly
LastEditTime: 2024-06-30 13:50:23
'''
from typing import List

class Solution:  # TLE!!!
    def dfs(self, target: int, loc: int) -> None:
        if loc == len(self.nums):
            self.ans += target == 0
            return
        self.dfs(target - self.nums[loc], loc + 1)
        self.dfs(target + self.nums[loc], loc + 1)
    
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        self.ans = 0
        self.nums = nums
        self.dfs(target, 0)
        return self.ans