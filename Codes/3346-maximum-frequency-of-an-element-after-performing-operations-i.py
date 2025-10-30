'''
Author: LetMeFly
Date: 2025-10-30 22:39:36
LastEditors: LetMeFly.xyz
LastEditTime: 2025-10-30 22:57:07
'''
from typing import List
from collections import Counter

class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        frequency = Counter(nums)
        l = r = 0
        ans = 0
        for target in range(nums[0], nums[-1] + 1):
            while target - nums[l] > k:
                l += 1
            while r < len(nums) and nums[r] - target <= k:
                r += 1
            ans = max(ans, min(r - l, numOperations + frequency[target]))
        return ans  # 刚刚差点忘记return