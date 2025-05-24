'''
Author: LetMeFly
Date: 2025-05-24 21:30:36
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-24 21:35:58
'''
from typing import List

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        return [i for i in len(words) if x in words[i]]