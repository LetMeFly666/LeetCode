'''
Author: LetMeFly
Date: 2024-05-26 09:26:59
LastEditors: LetMeFly
LastEditTime: 2024-05-26 09:28:10
'''
from typing import List

class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        prefix = [[0] * (len(matrix[0]) + 1) for _ in range(len(matrix) + 1)]
        vals = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                prefix[i + 1][j + 1] = prefix[i + 1][j] ^ prefix[i][j + 1] ^ prefix[i][j] ^ matrix[i][j]
                vals.append(prefix[i + 1][j + 1])
        vals.sort()
        return vals[-k]