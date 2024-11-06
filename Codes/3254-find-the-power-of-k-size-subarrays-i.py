'''
Author: LetMeFly
Date: 2024-11-06 17:04:07
LastEditors: LetMeFly.xyz
LastEditTime: 2024-11-06 17:12:53
'''
from typing import List

"""
# AC 版本1
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * (len(nums) - k + 1)
        for i in range(len(nums) - k + 1):
            ans[i] = nums[i + k - 1] if all(nums[j] == nums[j - 1] + 1 for j in range(i + 1, i + k)) else -1
        return ans
"""

class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        return [nums[i + k - 1] if all(nums[j] == nums[j - 1] + 1 for j in range(i + 1, i + k)) else -1 for i in range(len(nums) - k + 1)]