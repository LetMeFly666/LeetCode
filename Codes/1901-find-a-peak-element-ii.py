'''
Author: LetMeFly
Date: 2023-12-19 13:50:59
LastEditors: LetMeFly
LastEditTime: 2023-12-19 13:51:15
'''
from typing import List

class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        l, r = 0, len(mat)
        while l < r:
            mid = (l + r) >> 1
            maxLocation = mat[mid].index(max(mat[mid]))
            if mid - 1 >= 0 and mat[mid - 1][maxLocation] > mat[mid][maxLocation]:
                r = mid
            elif mid + 1 < len(mat) and mat[mid + 1][maxLocation] > mat[mid][maxLocation]:
                l = mid + 1
            else:
                return [mid, maxLocation]
        return []  # Fake Return
