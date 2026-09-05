'''
Author: LetMeFly
Date: 2026-09-05 08:24:28
LastEditors: LetMeFly.xyz
LastEditTime: 2026-09-05 08:35:17
'''
import itertools

class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        mini = list(itertools.accumulate(nums[::-1], min))[::-1]
        maxi = list(itertools.accumulate(nums, max))
        return next((i for i, (M, m) in enumerate(zip(maxi, mini)) if M - m <= k), -1)
