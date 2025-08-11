'''
Author: LetMeFly
Date: 2025-08-11 21:37:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-08-11 21:46:52
'''
from typing import List

class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        pows = []
        th = 0
        while n:
            if n & 1:
                pows.append(1 << th)
            th += 1
            n >>= 1
        perfix = [1] * (len(pows) + 1)
        for i in range(1, len(pows) + 1):
            perfix[i] = perfix[i - 1] * pows[i - 1]
        return [perfix[q[1] + 1] // perfix[q[0]] % 1000000007 for q in queries]