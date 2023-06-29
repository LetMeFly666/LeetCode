'''
Author: LetMeFly
Date: 2023-06-29 08:09:57
LastEditors: LetMeFly
LastEditTime: 2023-06-29 08:24:20
'''
from typing import List

class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        ans = [[0] * len(colsum) for _ in range(2)]
        cntUpper, cntLower = 0, 0
        for i in range(len(colsum)):
            if colsum[i] == 2:
                ans[0][i] = ans[1][i] = 1
                cntUpper += 1
                cntLower += 1
        for i in range(len(colsum)):
            if colsum[i] == 1:
                if cntUpper < upper:
                    ans[0][i] = 1
                    cntUpper += 1
                else:
                    ans[1][i] = 1
                    cntLower += 1
        return ans if cntUpper == upper and cntLower == lower else []