'''
Author: LetMeFly
Date: 2025-02-18 10:17:02
LastEditors: LetMeFly.xyz
LastEditTime: 2025-02-18 10:36:00
'''
from typing import List
from collections import defaultdict
from bisect import bisect_left, bisect_right


class RangeFreqQuery:

    def __init__(self, arr: List[int]):
        self.ma = defaultdict(list)
        for i, v in enumerate(arr):
            self.ma[v].append(i)

    def query(self, left: int, right: int, value: int) -> int:
        if value not in self.ma:
            return 0
        v = self.ma[value]
        return bisect_right(v, right) - bisect_left(v, left)


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)