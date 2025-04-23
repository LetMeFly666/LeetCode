'''
Author: LetMeFly
Date: 2025-04-23 13:20:37
LastEditors: LetMeFly.xyz
LastEditTime: 2025-04-23 13:22:37
'''
from collections import defaultdict

class Solution:
    def countLargestGroup(self, n: int) -> int:
        counter = defaultdict(int)
        maxTimes = 0
        for i in range(1, n + 1):
            cnt = sum(map(int, str(i)))
            counter[cnt] += 1
            maxTimes = max(maxTimes, counter[cnt])
        return sum(b == maxTimes for a, b in counter.items())