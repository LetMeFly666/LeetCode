'''
Author: LetMeFly
Date: 2024-09-22 23:32:46
LastEditors: LetMeFly
LastEditTime: 2024-09-22 23:35:58
'''
from typing import List
from collections import Counter

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        inDegree = Counter(y for x, y in trust)
        outDegree = Counter(x for x, y in trust)
        for th in range(n):
            if inDegree[th + 1] == n - 1 and not outDegree[th + 1]:
                return th + 1
        return -1