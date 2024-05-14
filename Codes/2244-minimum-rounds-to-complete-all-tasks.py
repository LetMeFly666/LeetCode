'''
Author: LetMeFly
Date: 2024-05-14 11:51:16
LastEditors: LetMeFly
LastEditTime: 2024-05-14 11:52:32
'''
from typing import List
from collections import defaultdict

class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        ma = defaultdict(int)
        for t in tasks:
            ma[t] += 1
        ans = 0
        for val, times in ma.items():
            if times == 1:
                return -1
            ans += (times + 2) // 3
        return ans