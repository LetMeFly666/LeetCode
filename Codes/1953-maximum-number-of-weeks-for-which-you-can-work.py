'''
Author: LetMeFly
Date: 2024-05-16 20:19:47
LastEditors: LetMeFly
LastEditTime: 2024-05-16 20:19:56
'''
from typing import List

class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        cnt, M  =0, 0
        for t in milestones:
            cnt += t
            M = max(M, t)
        return cnt if M * 2 <= cnt else (cnt - M) * 2 + 1