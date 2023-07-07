'''
Author: LetMeFly
Date: 2023-07-08 07:25:31
LastEditors: LetMeFly
LastEditTime: 2023-07-08 07:43:17
'''

""" # 方法一，二分，O(n log n) + O(1)
from typing import List
from bisect import bisect_left

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        for i in range(n):
            finding = target - numbers[i]
            loc = bisect_left(numbers, finding, i + 1)
            if loc < n and numbers[loc] == finding:
                return [i + 1, loc + 1]
        return []  # Fake Return
"""

# 方法二，双指针，O(n) + O(1)
from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            s = numbers[l] + numbers[r]
            if s == target:
                return [l + 1, r + 1]
            elif s < target:
                l += 1
            else:
                r -= 1
        return []  # Fake Return