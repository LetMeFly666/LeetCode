'''
Author: LetMeFly
Date: 2023-03-14 13:26:58
LastEditors: LetMeFly
LastEditTime: 2023-03-14 13:34:33
'''
from collections import defaultdict
from typing import List


class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        ans = len(wall)
        ma = defaultdict(int)
        for line in wall:
            cntWidth = 0
            for i in range(len(line) - 1):
                cntWidth += line[i]
                ma[cntWidth] += 1
        for loc, times in ma.items():
            ans = min(ans, len(wall) - times)
        return ans