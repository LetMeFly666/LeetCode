'''
Author: LetMeFly
Date: 2024-06-20 09:10:06
LastEditors: LetMeFly
LastEditTime: 2024-06-20 09:21:11
'''
from typing import List
from math import gcd

"""
[2,5,1,4]
"""
class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        ans = 0
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if gcd(ord(str(nums[i])[0]) - ord('0'), nums[j] % 10) == 1:
                    ans += 1
        return ans