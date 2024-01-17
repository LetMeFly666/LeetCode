'''
Author: LetMeFly
Date: 2024-01-17 22:48:44
LastEditors: LetMeFly
LastEditTime: 2024-01-17 22:48:50
'''
from typing import List
from collections import defaultdict

class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        ma = defaultdict(int)
        ans = 0
        for word in words:
            ans += ma[word[1] + word[0]]
            ma[word] += 1
        return ans