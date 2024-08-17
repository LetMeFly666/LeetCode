'''
Author: LetMeFly
Date: 2024-08-17 12:47:40
LastEditors: LetMeFly
LastEditTime: 2024-08-17 12:48:43
'''
from typing import List
from collections import defaultdict

class Solution:
    def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
        ma = defaultdict(int)
        maxTimes = 1
        for i in range(0, len(word), k):
            ma[word[i: i + k]] += 1
            maxTimes = max(maxTimes, ma[word[i: i + k]])
        return len(word) // k - maxTimes
