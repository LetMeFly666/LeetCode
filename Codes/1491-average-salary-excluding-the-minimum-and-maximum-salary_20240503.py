'''
Author: LetMeFly
Date: 2024-05-03 14:35:11
LastEditors: LetMeFly
LastEditTime: 2024-05-03 14:35:12
'''
from typing import List

class Solution:
    def average(self, salary: List[int]) -> float:
        return (sum(salary) - min(salary) - max(salary)) / (len(salary) - 2)