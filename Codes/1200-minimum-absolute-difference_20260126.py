'''
Author: LetMeFly
Date: 2026-01-26 23:38:09
LastEditors: LetMeFly.xyz
LastEditTime: 2026-01-26 23:45:24
'''
from typing import List

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        ans = []
        mini = 10000000
        for i in range(1, len(arr)):
            diff = arr[i] - arr[i - 1]
            if diff < mini:
                ans = [[arr[i - 1], arr[i]]]
                mini = diff
            elif diff == mini:
                ans.append([arr[i - 1], arr[i]])
        return ans