'''
Author: LetMeFly
Date: 2025-03-24 17:52:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-24 17:52:19
'''
from typing import List

class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return sum(s.startswith(word) for word in words)