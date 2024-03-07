'''
Author: LetMeFly
Date: 2024-03-07 15:50:24
LastEditors: LetMeFly
LastEditTime: 2024-03-07 15:51:38
'''
from typing import List

class Solution:  # AC,100.00%,78.26%
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        ans = [0] * len(word)
        val = 0
        for i in range(len(word)):
            val = val * 10 + (ord(word[i]) - ord('0'))
            val %= m
            ans[i] = 0 if val else 1
        return ans
