'''
Author: LetMeFly
Date: 2023-12-03 14:05:02
LastEditors: LetMeFly
LastEditTime: 2023-12-03 14:06:48
'''
from typing import List

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        l = len(cardPoints) - k
        cnt = 0
        s = 0
        for i in range(l):
            cnt += cardPoints[i]
            s += cardPoints[i]
        m = cnt
        for i in range(l, len(cardPoints)):
            cnt += cardPoints[i] - cardPoints[i - l]
            m = min(m, cnt)
            s += cardPoints[i]
        return s - m