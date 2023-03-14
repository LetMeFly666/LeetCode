'''
Author: LetMeFly
Date: 2023-03-14 12:48:20
LastEditors: LetMeFly
LastEditTime: 2023-03-14 12:53:05
'''
from typing import List


class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        ans = [[0 for i in range(len(colSum))] for j in range(len(rowSum))]
        for i in range(len(rowSum)):
            for j in range(len(colSum)):
                thisVal = min(rowSum[i], colSum[j])
                ans[i][j] = thisVal
                rowSum[i] -= thisVal
                colSum[j] -= thisVal
        return ans