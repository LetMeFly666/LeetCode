'''
Author: LetMeFly
Date: 2025-09-13 16:07:42
LastEditors: LetMeFly.xyz
LastEditTime: 2025-09-13 16:19:20
'''
class Solution:
    mask = 1<<0 | 1<<4 | 1<<8 | 1<<14 | 1<<20
    def maxFreqSum(self, s: str) -> int:
        times = [0] * 26
        for c in s:
            times[ord(c) - ord('a')] += 1
        c = [0, 0]
        for i in range(26):
            idx = self.mask >> i & 1
            c[idx] = max(c[idx], times[i])
        return c[0] + c[1]