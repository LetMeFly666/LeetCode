'''
Author: LetMeFly
Date: 2024-07-02 09:32:09
LastEditors: LetMeFly
LastEditTime: 2024-07-02 09:37:41
'''
from typing import List
from math import sqrt

class Solution:
    def isPrime(self, n: int) -> bool:
        if n == 1:
            return False
        for i in range(2, int(sqrt(n)) + 1):
            if n % i == 0:
                return False
        return True
    
    def maximumPrimeDifference(self, nums: List[int]) -> int:
        m, M = 10000000, -1
        for i in range(len(nums)):
            if self.isPrime(nums[i]):
                m, M = min(m, i), max(M, i)
        return M - m