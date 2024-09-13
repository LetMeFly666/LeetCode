'''
Author: LetMeFly
Date: 2024-09-13 13:09:24
LastEditors: LetMeFly
LastEditTime: 2024-09-13 13:12:48
'''
from typing import List
from collections import deque

class Solution:
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
        ans = sumCosts = 0
        l = 0
        q = deque()
        for r in range(len(chargeTimes)):
            while q and chargeTimes[r] >= chargeTimes[q[-1]]:
                q.pop()
            q.append(r)
            sumCosts += runningCosts[r]

            while q and chargeTimes[q[0]] + (r - l + 1) * sumCosts > budget:
                if l == q[0]:
                    q.popleft()
                sumCosts -= runningCosts[l]
                l += 1
            
            ans = max(ans, r - l + 1)
        return ans
