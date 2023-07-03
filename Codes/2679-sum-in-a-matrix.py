'''
Author: LetMeFly
Date: 2023-07-04 06:53:39
LastEditors: LetMeFly
LastEditTime: 2023-07-04 06:57:04
'''
from typing import List

class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        n, m = len(nums), len(nums[0])
        for line in nums:
            line.sort()
        ans = 0
        for j in range(m - 1, -1, -1):
            M = 0
            for i in range(n):
                M = max(M, nums[i][j])
            ans += M
        return ans