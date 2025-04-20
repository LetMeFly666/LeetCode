'''
Author: LetMeFly
Date: 2025-04-20 19:53:58
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-20 20:05:51
'''
from typing import List
from collections import Counter

class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        return sum((group + total) // (group + 1) * (group + 1) for group, total in Counter(answers).items())