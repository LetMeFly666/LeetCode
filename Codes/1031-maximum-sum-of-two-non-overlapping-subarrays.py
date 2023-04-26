'''
Author: LetMeFly
Date: 2023-04-26 12:39:49
LastEditors: LetMeFly
LastEditTime: 2023-04-26 13:00:25
'''
from typing import List

class Solution:
    def calculate1(self, a: List[int], ll: int, lr: int):
        sl = sum(a[i] for i in range(ll))
        sr = sum(a[i] for i in range(ll, ll + lr))
        ml = sl
        ans = ml + sr
        i, j = ll, ll + lr
        while j < len(a):
            sl = sl + a[i] - a[i - ll]
            sr = sr + a[j] - a[j - lr]
            ml = max(ml, sl)
            ans = max(ans, ml + sr)
            i, j = i + 1, j + 1
        return ans        
    
    def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int:
        return max(self.calculate1(nums, firstLen, secondLen), self.calculate1(nums, secondLen, firstLen))
