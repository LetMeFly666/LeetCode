'''
Author: LetMeFly
Date: 2024-09-01 14:56:10
LastEditors: LetMeFly
LastEditTime: 2024-09-01 14:59:32
'''
from typing import List

class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        return sum(startTime[i] <= queryTime <= endTime[i] for i in range(len(startTime)))