'''
Author: LetMeFly
Date: 2024-08-30 22:00:44
LastEditors: LetMeFly
LastEditTime: 2024-08-30 22:07:39
'''
from typing import List

class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        ans = 0
        n = max(nums)
        while n:  # while nums[0]的话可能会有[0, 1]的情况  # 后续更新：忽然发现题目限定是正数，有点过考虑了
            n //= 10
            times = [0] * 10
            for th, x in enumerate(nums):
                times[x % 10] += 1
                nums[th] //= 10
            for i in range(10):
                ans += times[i] * (len(nums) - times[i])
        return ans // 2