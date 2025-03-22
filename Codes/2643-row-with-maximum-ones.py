'''
Author: LetMeFly
Date: 2025-03-22 22:44:18
LastEditors: LetMeFly.xyz
LastEditTime: 2025-03-22 22:44:32
'''
from typing import List

class Solution:
    def rowAndMaximumOnes(self, mat: List[List[int]]) -> List[int]:
        mx, ans = 0, 0
        for i in range(len(mat)):
            cnt = sum(mat[i])
            if cnt > mx:
                mx, ans = cnt, i
        return [ans, mx]