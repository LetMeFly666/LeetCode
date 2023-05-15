'''
Author: LetMeFly
Date: 2023-05-15 10:46:32
LastEditors: LetMeFly
LastEditTime: 2023-05-15 10:55:38
'''
from typing import List
from collections import defaultdict

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        ma = defaultdict(int)
        n, m = len(matrix), len(matrix[0])
        ans = 0
        for i in range(n):
            thisLine = ''
            for j in range(m):
                thisLine += chr(ord('0') + matrix[i][j] ^ matrix[i][0])
            ma[thisLine] += 1
            ans = max(ans, ma[thisLine])
        return ans