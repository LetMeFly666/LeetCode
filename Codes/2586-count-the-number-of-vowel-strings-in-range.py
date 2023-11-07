'''
Author: LetMeFly
Date: 2023-11-07 22:31:45
LastEditors: LetMeFly
LastEditTime: 2023-11-07 22:33:34
'''
from typing import List

class Solution:
    def can(self, c: str) -> bool:
        return c in 'aeiou'
    
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        return sum(self.can(words[i][0]) and self.can(words[i][-1]) for i in range(left, right + 1))