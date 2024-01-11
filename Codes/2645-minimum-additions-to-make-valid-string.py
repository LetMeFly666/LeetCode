'''
Author: LetMeFly
Date: 2024-01-11 15:35:58
LastEditors: LetMeFly
LastEditTime: 2024-01-11 15:37:17
'''
class Solution:
    def addMinimum(self, word: str) -> int:
        cntABC = 1
        for i in range(1, len(word)):
            if word[i] <= word[i - 1]:
                cntABC += 1
        return cntABC * 3 - len(word)