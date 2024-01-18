'''
Author: LetMeFly
Date: 2024-01-18 19:32:37
LastEditors: LetMeFly
LastEditTime: 2024-01-18 19:34:06
'''
from typing import List

class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        all_ = sum(beans)
        ans = all_
        for i, thisBean in enumerate(beans):
            ans = min(ans, all_ - thisBean * (len(beans) - i))
        return ans