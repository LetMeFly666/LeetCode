'''
Author: LetMeFly
Date: 2023-02-28 10:13:23
LastEditors: LetMeFly
LastEditTime: 2023-02-28 10:30:19
'''
from collections import defaultdict
from typing import List


class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        ma = defaultdict(int)
        for a, b in items1:
            ma[a] += b
        for a, b in items2:
            ma[a] += b
        return sorted([[a, b] for a, b in ma.items()])
