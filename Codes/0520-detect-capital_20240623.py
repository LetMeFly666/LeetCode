'''
Author: LetMeFly
Date: 2024-06-23 18:58:34
LastEditors: LetMeFly
LastEditTime: 2024-06-23 19:00:19
'''
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cntLower = sum(word[i].islower() for i in range(1, len(word)))
        return cntLower == len(word) - 1 or cntLower == 0 and word[0].isupper()