'''
Author: LetMeFly
Date: 2024-05-27 21:39:24
LastEditors: LetMeFly
LastEditTime: 2024-05-27 21:40:37
'''
from typing import List

class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        target = mean * (len(rolls) + n) - sum(rolls)
        if target < n or target > n * 6:
            return []
        ans = [target // n] * n
        for i in range(target % n):
            ans[i] += 1
        return ans
