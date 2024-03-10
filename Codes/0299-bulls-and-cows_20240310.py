'''
Author: LetMeFly
Date: 2024-03-10 11:51:28
LastEditors: LetMeFly
LastEditTime: 2024-03-10 11:51:38
'''
from collections import Counter

class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        A = sum(secret[i] == guess[i] for i in range(len(secret)))
        AB = sum((Counter(secret) & Counter(guess)).values())
        return f'{A}A{AB - A}B'
