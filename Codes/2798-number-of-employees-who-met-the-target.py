'''
Author: LetMeFly
Date: 2024-04-30 10:37:01
LastEditors: LetMeFly
LastEditTime: 2024-04-30 10:37:03
'''
from typing import List

class Solution:
    def numberOfEmployeesWhoMetTarget(self, hours: List[int], target: int) -> int:
        return sum(t >= target for t in hours)