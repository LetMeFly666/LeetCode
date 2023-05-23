'''
Author: LetMeFly
Date: 2023-05-23 11:46:48
LastEditors: LetMeFly
LastEditTime: 2023-05-23 11:54:00
'''
from typing import List
from collections import defaultdict


class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], numWanted: int, useLimit: int) -> int:
        v = list(zip(values, labels))
        v.sort(key=lambda x : -x[0])
        ans = 0
        cnt = 0
        ma = defaultdict(int)
        for value, label in v:
            if ma[label] == useLimit:
                continue
            ma[label] += 1
            cnt += 1
            ans += value
            if cnt == numWanted:
                break
        return ans
