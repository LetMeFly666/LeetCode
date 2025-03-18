'''
Author: LetMeFly
Date: 2025-03-18 23:46:52
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-18 23:48:14
'''
from typing import List
from math import sqrt

class Solution:
    def isPrime(self, n: int) -> bool:
        if n < 2:
            return False
        for i in range(2, int(sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True
    
    def diagonalPrime(self, nums: List[List[int]]) -> int:
        ans = 0
        for i in range(len(nums)):
            if self.isPrime(nums[i][i]):
                ans = max(ans, nums[i][i])
            if self.isPrime(nums[i][len(nums) - i - 1]):
                ans = max(ans, nums[i][len(nums) - i - 1])
        return ans