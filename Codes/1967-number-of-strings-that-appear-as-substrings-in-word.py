'''
Author: LetMeFly
Date: 2026-06-29 15:07:05
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-29 15:19:06
'''
from typing import List

class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        return sum(p in word for p in patterns)
