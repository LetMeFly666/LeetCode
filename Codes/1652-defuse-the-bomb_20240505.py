'''
Author: LetMeFly
Date: 2024-05-05 14:03:07
LastEditors: LetMeFly
LastEditTime: 2024-05-05 14:07:35
'''
from typing import List

class Solution:
    def next(self, i: int) -> int:
        return (i + 1) % self.n
    
    def decrypt(self, code: List[int], k: int) -> List[int]:
        self.n = len(code)
        ans = [0] * self.n
        if not k:
            return ans
        l, r, s = 0, 0, 0
        if k > 0:
            l = 1
            for r in range(l, k + 1):
                s += code[r]
        else:
            r = self.n - 1
            for l in range(r, self.n + k - 1, -1):
                s += code[l]
        for i in range(self.n):
            ans[i] = s
            s -= code[l]
            l = self.next(l)
            r = self.next(r)
            s += code[r]
        return ans