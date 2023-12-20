'''
Author: LetMeFly
Date: 2023-12-20 14:07:10
LastEditors: LetMeFly
LastEditTime: 2023-12-20 14:07:24
'''
from typing import List

class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:
        if len(s) != len(words):
            return False
        for i in range(len(s)):
            if s[i] != words[i][0]:
                return False
        return True