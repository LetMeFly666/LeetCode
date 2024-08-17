'''
Author: LetMeFly
Date: 2024-08-17 12:50:32
LastEditors: LetMeFly
LastEditTime: 2024-08-17 12:51:14
'''
from collections import Counter

class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        return len(word) // k - max(Counter(word[i : i + k] for i in range(0, len(word), k)).values())