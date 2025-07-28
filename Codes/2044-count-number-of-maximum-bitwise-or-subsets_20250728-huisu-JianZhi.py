'''
Author: LetMeFly
Date: 2025-07-28 13:38:06
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-28 20:40:58
'''
from typing import List

class Solution:
    def dfs(self, th: int, now: int) -> None:
        if now == self.M:
            self.ans += 1 << (len(self.nums) - th)
            return
        if th == len(self.nums):
            return
        self.dfs(th + 1, now)
        self.dfs(th + 1, now | self.nums[th])
    
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        self.ans = 0
        self.nums = nums
        self.M = 0
        for t in nums:
            self.M |= t
        self.dfs(0, 0)
        return self.ans