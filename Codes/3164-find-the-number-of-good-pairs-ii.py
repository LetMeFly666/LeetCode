'''
Author: LetMeFly
Date: 2024-10-11 22:53:45
LastEditors: LetMeFly
LastEditTime: 2024-10-11 22:56:00
'''
from typing import List
from collections import defaultdict
from math import sqrt

class Solution:
    def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
        ma = defaultdict(int)
        for t in nums1:
            if t % k:
                continue
            t //= k
            sqrt_ = int(sqrt(t))
            for i in range(1, sqrt_ + 1):
                if t % i == 0:
                    ma[i] += 1
                    ma[t // i] += 1
            if sqrt_ * sqrt_ == t:
                ma[sqrt_] -= 1
        ans = 0
        for t in nums2:
            ans += ma[t]
        return ans