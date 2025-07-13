'''
Author: LetMeFly
Date: 2025-07-13 21:44:10
LastEditors: LetMeFly.xyz
LastEditTime: 2025-07-13 22:10:26
'''
from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        cnt = sum(endTime[i] - startTime[i] for i in range(k))
        n = len(startTime)
        ans = 0
        for i in range(k, n + 1):
            l = (endTime[i - k - 1] if i > k else 0) + cnt
            r = eventTime if i == n + 1 else startTime[i]
            ans = max(ans, r - l)
            if i == n + 1:
                break
            cnt += endTime[i] - startTime[i]
            cnt -= endTime[i - k] - startTime[i - k]
        return ans