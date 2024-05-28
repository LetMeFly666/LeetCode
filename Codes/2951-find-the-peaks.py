'''
Author: LetMeFly
Date: 2024-05-28 22:15:06
LastEditors: LetMeFly
LastEditTime: 2024-05-28 22:15:15
'''
from typing import List

class Solution:
    def findPeaks(self, mountain: List[int]) -> List[int]:
        ans = []
        for i in range(1, len(mountain) - 1):
            if mountain[i] > mountain[i - 1] and mountain[i] > mountain[i + 1]:
                ans.append(i)
        return ans