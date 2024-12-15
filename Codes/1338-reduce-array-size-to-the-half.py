'''
Author: LetMeFly
Date: 2024-12-15 15:06:44
LastEditors: LetMeFly.xyz
LastEditTime: 2024-12-15 15:09:07
'''
from typing import List
from collections import Counter

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        ma = Counter(arr)
        times = [t for i, t in ma.items()]
        times.sort()
        ans, cnt, i = 0, 0, len(times) - 1
        while cnt < len(arr) // 2:
            ans += 1
            cnt += times[i]
            i -= 1
        return ans