'''
Author: LetMeFly
Date: 2023-05-05 20:03:16
LastEditors: LetMeFly
LastEditTime: 2023-05-05 20:07:38
'''
from typing import List

class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        ans, M, lastTime = 0, -1, 0
        for log in logs:
            if log[1] - lastTime > M:
                M = log[1] - lastTime
                ans = log[0]
            elif log[1] - lastTime == M:
                ans = min(ans, log[0])
            lastTime = log[1]
        return ans