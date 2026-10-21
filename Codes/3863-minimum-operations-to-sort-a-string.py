'''
Author: LetMeFly
Date: 2026-10-21 08:00:18
LastEditors: LetMeFly.xyz
LastEditTime: 2026-10-21 16:50:30
'''
class Solution:
    def minOperations(self, s: str) -> int:
        if all(s[i] >= s[i - 1] for i in range(1, len(s))):
            return 0
        if len(s) == 2:
            return -1
        mn = min(s)
        mx = max(s)
        if s[0] == mn or s[-1] == mx:
            return 1
        if mn in s[1:-1] or mx in s[1:-1]:
            return 2
        return 3
