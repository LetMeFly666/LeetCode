'''
Author: LetMeFly
Date: 2024-05-17 17:03:47
LastEditors: LetMeFly
LastEditTime: 2024-05-17 17:05:16
'''
from typing import List

class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        a = sorted(zip(difficulty, profit)) + [(1000000, 0)]
        worker.sort()
        M = 0
        ans = 0
        it = 0
        for thisWorker in worker:
            while a[it][0] <= thisWorker:
                M = max(M, a[it][1])
                it += 1
            ans += M
        return ans