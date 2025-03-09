'''
Author: LetMeFly
Date: 2025-03-09 14:04:11
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-09 14:07:29
'''
from typing import List

class Solution:
    def search(self, items: List[List[int]], target: int) -> int:
        l, r = 0, len(items) - 1
        while l <= r:
            mid = (l + r) >> 1
            if items[mid][0] > target:
                r = mid - 1
            else:
                l = mid + 1
        return l
    
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        cnt = 0
        for i, (_, val) in enumerate(items):
            cnt = items[i][1] = max(cnt, val)
        for i, q in enumerate(queries):
            index = self.search(items, q)
            queries[i] = items[index - 1][1] if index else 0
        return queries