'''
Author: LetMeFly
Date: 2024-05-30 16:47:08
LastEditors: LetMeFly
LastEditTime: 2024-05-30 16:52:04
'''
from typing import List

class Solution:
    def add(self, times, n) -> None:
        for i in range(2, -1, -1):
            if n > times[i]:
                times[i] = n
                break
        if times[2] > times[1]:
            times[1], times[2] = times[2], times[1]
        if times[1] > times[0]:
            times[0], times[1] = times[1], times[0]
    
    def getTimes(self, times) -> int:
        return max(
            min(times),
            min(times[0] - 1, times[1]),
            times[0] - 2
        )

    def maximumLength(self, s: str) -> int:
        times = [[0, 0, 0] for _ in range(26)]
        from_ = 0
        for i in range(1, len(s) + 1):
            if i == len(s) or s[i] != s[i - 1]:
                self.add(times[ord(s[i - 1]) - ord('a')], i - from_)
                from_ = i
        ans = 0
        for i in range(26):
            ans = max(ans, self.getTimes(times[i]))
        return ans if ans else -1