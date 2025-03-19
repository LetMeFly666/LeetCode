'''
Author: LetMeFly
Date: 2025-03-19 19:56:03
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-19 19:57:12
'''
from typing import List
from collections import defaultdict


class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        ans: List[List[int]] = []
        ma = defaultdict(int)
        for t in nums:
            ma[t] += 1
            if ma[t] > len(ans):
                ans.append([])
            ans[ma[t] - 1].append(t)
        return ans
