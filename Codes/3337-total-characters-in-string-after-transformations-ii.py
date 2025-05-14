'''
Author: LetMeFly
Date: 2025-05-14 22:01:41
LastEditors: LetMeFly.xyz
LastEditTime: 2025-05-14 23:46:10
'''
from typing import List

MOD = 1000000007

class Solution:
    def mul(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        ans = [[0] * 26 for _ in range(26)]
        for i in range(26):
            for k in range(26):
                for j in range(26):
                    ans[i][j] = (ans[i][j] + a[i][k] * b[k][j]) % MOD
        return ans

    def pow(self, a: List[List[int]], b: int) -> List[List[int]]:
        ans = [[0] * 26 for _ in range(26)]
        for i in range(26):
            ans[i][i] = 1
        while b:
            if b & 1:
                ans = self.mul(ans, a)
            a = self.mul(a, a)
            b >>= 1
        return ans
    
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        M = [[0] * 26 for _ in range(26)]
        for i, v in enumerate(nums):
            for j in range(1, v + 1):
                M[i][(i + j) % 26] = 1
        Mt = self.pow(M, t)
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord('a')] += 1
        ans = 0
        for i in range(26):
            ans += sum(Mt[i]) * cnt[i]
        return ans % MOD
