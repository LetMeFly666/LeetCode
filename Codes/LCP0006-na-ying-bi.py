'''
Author: LetMeFly
Date: 2023-09-20 10:41:51
LastEditors: LetMeFly
LastEditTime: 2023-09-20 10:43:11
'''
from typing import List

class Solution:
    def minCount(self, coins: List[int]) -> int:
        return sum((i + 1) // 2 for i in coins)