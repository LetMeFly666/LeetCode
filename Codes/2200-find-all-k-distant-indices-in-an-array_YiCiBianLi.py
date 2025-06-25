'''
Author: LetMeFly
Date: 2025-06-25 22:24:22
LastEditors: LetMeFly.xyz
LastEditTime: 2025-06-25 22:38:19
'''
from typing import List

class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        ans = []
        last = 0
        for i in range(len(nums)):
            if nums[i] == key:
                for j in range(max(last, i - k), min(len(nums), i + k + 1)):
                    ans.append(j)
                last = i + k + 1
        return ans