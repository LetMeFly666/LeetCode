'''
Author: LetMeFly
Date: 2023-05-14 09:15:34
LastEditors: LetMeFly
LastEditTime: 2023-05-14 09:36:05
'''
from typing import List
from collections import defaultdict

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        ma = defaultdict(int)
        for t in barcodes:
            ma[t] += 1
        barcodes.sort(key=lambda x: (-ma[x], x))
        ans = [0] * len(barcodes)
        ans[::2] = barcodes[:(len(barcodes) + 1) // 2]
        ans[1::2] = barcodes[(len(barcodes) + 1) // 2:]
        return ans