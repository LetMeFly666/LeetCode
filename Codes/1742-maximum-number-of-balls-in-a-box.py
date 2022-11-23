'''
Author: LetMeFly
Date: 2022-11-23 09:38:55
LastEditors: LetMeFly
LastEditTime: 2022-11-23 09:40:21
'''
from collections import Counter


class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        return max(Counter(sum(map(int, str(i))) for i in range(lowLimit, highLimit + 1)).values())