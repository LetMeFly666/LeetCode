'''
Author: LetMeFly
Date: 2026-06-14 19:20:02
LastEditors: LetMeFly.xyz
LastEditTime: 2026-06-14 19:22:15
'''
from typing import List

class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        return ''.join(chr(ord('a') + (25 - sum(weights[ord(c) - ord('a')] for c in word) % 26)) for word in words)
