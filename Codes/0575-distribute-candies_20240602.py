'''
Author: LetMeFly
Date: 2024-06-02 09:40:48
LastEditors: LetMeFly
LastEditTime: 2024-06-02 09:41:08
'''
from typing import List

class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(set(candyType)), len(candyType) // 2)