'''
Author: LetMeFly
Date: 2023-06-07 13:10:50
LastEditors: LetMeFly
LastEditTime: 2023-06-07 13:15:40
'''
from typing import List

class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        ans = sum(reward2)
        first = [reward1[i] - reward2[i] for i in range(len(reward1))]
        first.sort()
        while k:
            ans += first[-k]
            k -= 1
        return ans