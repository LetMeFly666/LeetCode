'''
Author: LetMeFly
Date: 2026-07-08 14:31:47
LastEditors: LetMeFly.xyz
LastEditTime: 2026-07-08 14:37:33
'''
from typing import List

N = 100000
MOD = 1000000007
pow = [1] * N
for i in range(1, N):
    pow[i] = pow[i] * 10 % MOD

class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(queries)
        sum = [0] * (n + 1)
        con = [0] * (n + 1)
        cnt1 = [0] * (n + 1)
        for i in range(n):
            if s[i] == '0':
                sum[i + 1] = sum[i]
                con[i + 1] = con[i]
                cnt1[i + 1] = cnt1[i]
            else:
                v = ord(s[i]) - ord('0')
                sum[i + 1] = sum[i] + v
                con[i + 1] = (con[i] * 10 + v) % MOD
                cnt1[i + 1] = cnt1[i] + 1
        
        ans = [0] * len(queries)
        for i, (l, r) in enumerate(queries):
            su = sum[r + 1] - sum[l]
            cn = (con[r + 1] - con[l] * pow[cnt1[r + 1] - cnt1[l]]) % MOD + MOD
        ans[i] = su * cn % MOD
        return ans
