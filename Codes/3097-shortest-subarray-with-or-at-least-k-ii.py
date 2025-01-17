'''
Author: LetMeFly
Date: 2025-01-17 12:24:55
LastEditors: LetMeFly.xyz
LastEditTime: 2025-01-17 12:29:16
'''
from typing import List

class Solution:
    def calc(self) -> int:
        ans = 0
        for i in range(30):
            if self.cnt[i]:
                ans += 1 << i
        return ans
    
    def add(self, a: int) -> None:
        for i in range(30):
            self.cnt[i] += a >> i & 1
    
    def sub(self, a: int) -> None:
        for i in range(30):
            self.cnt[i] -= a >> i & 1

    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if not k:
            return 1
        ans = 1000000
        r = 0
        self.cnt = [0] * 30
        for l in range(len(nums)):
            if l:
                self.sub(nums[l - 1])
            while r < len(nums) and self.calc() < k:
                self.add(nums[r])
                r += 1
            if self.calc() >= k:
                ans = min(ans, r - l)
        return -1 if ans == 1000000 else ans