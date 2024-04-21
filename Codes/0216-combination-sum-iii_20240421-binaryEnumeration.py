'''
Author: LetMeFly
Date: 2024-04-21 13:38:50
LastEditors: LetMeFly
LastEditTime: 2024-04-21 13:45:51
'''
from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        for i in range(1 << 9):
            if i.bit_count() != k:  # Python 3.9.4中似乎无此函数
                continue
            thisSolution = []
            thisCnt = 0
            for j in range(9):
                if i & (1 << j):
                    thisCnt += j + 1
                    thisSolution.append(j + 1)
            if thisCnt == n:
                ans.append(thisSolution)
        return ans