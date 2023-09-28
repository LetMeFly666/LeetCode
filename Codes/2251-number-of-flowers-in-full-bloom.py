'''
Author: LetMeFly
Date: 2023-09-28 11:00:22
LastEditors: LetMeFly
LastEditTime: 2023-09-28 11:02:52
'''
from typing import List
from bisect import bisect_right

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        start = sorted([f[0] for f in flowers])
        end = sorted([f[1] for f in flowers])
        return [bisect_right(start, p) - bisect_right(end, p - 1) for p in people]
