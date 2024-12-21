'''
Author: LetMeFly
Date: 2024-12-21 17:55:19
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-21 17:56:05
'''
from typing import List

class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        return sorted(score, key=lambda a: -a[k])